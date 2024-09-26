
// Hello World


#include <atomic>
#include <iostream>

template<typename T>
class TSharedPtr {

    struct TControlBlock {
        T *DataPtr;
        std::atomic<int> RefCount;

        TControlBlock(T *DataPtr)
            : DataPtr(DataPtr), RefCount(1) {}

        ~TControlBlock() {
            delete DataPtr;
        }

        auto add_ref_cnt() -> void {
            RefCount.fetch_add(1, std::memory_order_relaxed);
        }

        auto dec_ref_cnt() -> bool {
            if (RefCount.fetch_sub(1, std::memory_order_acq_rel) == 1) {
                std::atomic_thread_fence(std::memory_order_acquire);
                return true;
            }
            return false;
        }
    };

    TControlBlock *Control;

  public:
    TSharedPtr()
        : Control(nullptr) {}

    explicit TSharedPtr(T *DataPtr)
        : Control(new TControlBlock(DataPtr)) {}

    // Copy Constructor
    TSharedPtr(TSharedPtr const &Other)
        : Control(Other.Control) {
        if (Control) {
            Control->add_ref_cnt();
        }
    }

    // Move Constructor
    TSharedPtr(TSharedPtr &&Other) noexcept
        : Control(Other.Control) {
        Other.Control = nullptr;
    }

    // Copy Assignment
    auto operator=(TSharedPtr const &Other) -> TSharedPtr & {
        if (Control != Other.Control) {
            if (Control && Control->dec_ref_cnt()) {
                delete Control;
            }
            Control = Other.Control;
            if (Control) {
                Control->add_ref_cnt();
            }
        }
        return *this;
    }

    // Move Assignment
    auto operator=(TSharedPtr &&Other) noexcept -> TSharedPtr & {
        if (Control != Other.Control) {
            if (Control && Control->dec_ref_cnt()) {
                delete Control;
            }
            Control = Other.Control;
            Other.Control = nullptr;
        }
        return *this;
    }

    ~TSharedPtr() {
        if (Control && Control->dec_ref_cnt()) {
            delete Control;
        }
    }

    T &operator*() const {
        return *(Control->DataPtr);
    }

    T *operator->() const {
        return Control->DataPtr;
    }

    auto get() const -> T * {
        return Control ? Control->DataPtr : nullptr;
    }

    auto use_count() const -> int {
        return Control ? Control->RefCount.load(std::memory_order_relaxed) : 0;
    }

    auto reset() -> void {
        if (Control && Control->dec_ref_cnt()) {
            delete Control;
        }
        if (Control) {
            Control = new TControlBlock(nullptr);
        } else {
            Control = nullptr;
        }
    }
};

int main() {

    std::cout << "Hello World" << std::endl;

    auto sp1 = TSharedPtr<int>(new int(42));

    auto sp2 = sp1;

    {
        auto sp3 = sp1;
        std::cout << sp1.use_count() << std::endl;
    }

    std::cout << sp1.use_count() << std::endl;

    sp1.reset();

    std::cout << sp1.use_count() << std::endl;

    return 0;
}
