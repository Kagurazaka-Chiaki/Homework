from pathlib import Path


def create_file(name: str, suffix: str):
    # 创建一个文件
    file_path = Path(f"{name}{suffix}")
    file_path.touch(exist_ok=True)  # exist_ok=True表示如果文件已存在则不报错
    print(f"File created: {file_path.resolve()}")

def main():
    create_file(f"PIO10", ".cpp")

if __name__ == "__main__":
    main()