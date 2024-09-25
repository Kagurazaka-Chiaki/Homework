

#ifndef MINICORO_HPP
#define MINICORO_HPP

#include <iostream>
#include <coroutine>
#include <exception>
#include <fstream>


namespace minicoro {

    enum class task_status {
        CORO_NEW = 0,
        CORO_RUNNING,
        CORO_FINISHED
    };


    template<typename T>
    struct generator {

        class exhausted_exception : public std::exception {
        };

        struct promise_type {

            T current_value = {};

            bool is_ready = false;

            auto initial_suspend() -> std::suspend_always {
                return std::suspend_always{};
            }


            auto final_suspend() noexcept -> std::suspend_always {
                return {};
            }

            auto get_return_object() -> generator {
                return generator{std::coroutine_handle<promise_type>::from_promise(*this)};
            }

            static auto get_return_object_on_allocation_failure() -> generator {
                return generator{nullptr};
            }

            auto unhandled_exception() -> void {
                std::terminate();
            }

            auto yield_value(T value) -> std::suspend_always {
                current_value = value;
                is_ready = true;
                return {};
            }

            auto await_transform(T value) -> std::suspend_always {
                current_value = value;
                is_ready = true;
                return {};
            }

            void return_void() {}
        };

        std::coroutine_handle<promise_type> coro_handle;

        explicit generator(std::coroutine_handle<promise_type> handle) noexcept
                : coro_handle(handle) {
        }

        generator(generator &&other) noexcept
                : coro_handle(std::exchange(other.coro_handle, nullptr)) {
        }

        generator &operator=(generator &&other) noexcept {
            if (this != &other) {
                coro_handle = other.coro_handle;
                other.coro_handle = nullptr;
            }
            return *this;
        }

        generator(const generator &) = delete;

        generator &operator=(const generator &) = delete;

        ~generator() {
            if (coro_handle) {
                coro_handle.destroy();
            }
        }

        [[nodiscard]] auto has_next() const -> bool {
            if (coro_handle.done()) {
                return false;
            }

            if (!coro_handle.promise().is_ready) {
                coro_handle.resume();
            }

            if (coro_handle.done()) {
                return false;
            } else {
                return true;
            }
        }

        auto next() const -> T {
            if (has_next()) {
                coro_handle.promise().is_ready = false;

                return coro_handle.promise().current_value;
            }
            throw exhausted_exception();

        }

        template<typename ...type_args>
        auto static from(type_args ...args) -> generator {
            (co_yield args, ...);
        }

        template<typename F>
        auto map(F f) -> generator<std::invoke_result_t<F, T>> {
            while (has_next()) {
                co_yield f(next());
            }
        }

        template<typename F>
        auto flat_map(F f) -> std::invoke_result_t<F, T> {
            while (has_next()) {
                auto g = f(next());
                while (g.has_next()) {
                    co_yield g.next();
                }
            }
        }

        template<typename F>
        auto for_each(F f) -> void {
            while (has_next()) {
                f(next());
            }
        }

        template<typename R, typename F>
        auto fold(R initial, F f) -> R {
            R acc = initial;
            while (has_next()) {
                acc = f(acc, next());
            }
            return acc;
        }

        template<typename F>
        auto filter(F f) -> generator {
            while (has_next()) {
                T value = next();
                if (f(value)) {
                    co_yield value;
                }
            }
        }

        auto take(int n) -> generator {
            int i = 0;
            while (i++ < n && has_next()) {
                co_yield next();
            }
        }

        template<typename F>
        auto take_until(F f) -> generator {
            while (has_next()) {
                T value = next();
                if (f(value)) {
                    co_yield value;
                } else {
                    break;
                }
            }
        }

        auto static lerp(T a, T b, float t) -> generator {
            float i = 0.0f;
            while (i < 1.0f) {
                co_yield a + (b - a) * i;
                i += t;
            }
        }

    };



    template<typename T>
    auto log_to_file(std::string const& file_name, generator<T> &gen) -> void {

        std::fstream file;

        file.open(file_name, std::ios::out | std::ios::app);

        while (gen.has_next()) {
            auto res = gen.next();
            std::cout << res << std::endl;
            file << res << std::endl;
        }
    }


    template<typename T>
    struct coro_result{

    private:
        T value;

        std::exception_ptr exception_ptr;


    };

} // namespace minicoro

#endif // MINICORO_HPP