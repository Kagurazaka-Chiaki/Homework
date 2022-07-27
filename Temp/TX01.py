# -*- coding:utf-8 -*-


from enum import Enum
import sys

import numpy as np


class State(Enum):
    End = -1
    Empty = 0
    Start = 1
    Action = 2

    _0 = 6
    _1 = 7

    _00 = 8
    _01 = 9
    _10 = 10
    _11 = 11

    _000 = 12
    _001 = 13
    _010 = 14
    _011 = 15

    _100 = 16
    _101 = 17
    _110 = 18
    _111 = 18


class Machine(object):
    def __init__(self, data: list[any] = None) -> None:
        self._state = State.Empty  # type: State
        self._off = True           # type: bool
        self._index = -1           # type: int
        self._data = data          # type: list[any]
        self._length = len(data)   # type: int

    def detail(self) -> None:
        print(f"{self._state}, index: {self._index}, length: {self._length}")
        print("----" * (self._length + 2))
        if self._index == -1:
            space = " " * (self._index + 1 + 1)
        else:
            space = " " * (self._index * 4 + 5)
        print(f"{space}|\n{space}v\n[*] ", end="")
        for i in self._data:
            print(f"[{i}] ", end="")
        print("[*]")
        print("----" * (self._length + 2))

    def go_prev(self) -> None:  # [0, n - 1]
        if self._index > 0:
            self._index -= 1
        else:
            self.go_state(State.End)

    def go_curr(self) -> any:
        if self._state is State.End:
            return None
        else:
            return self._data[self._index]

    def go_next(self) -> None:  # [0, n - 1]
        if self._index < self._length - 1:
            self._index += 1
        else:
            self.go_state(State.End)

    def go_state(self, state: State) -> None:
        self._state = state

    def update(self) -> bool:

        if self._state == State.Empty:
            print(f"current state {self._state}")
            self.go_state(State.Start)
        elif self._state == State.Start:
            print(f"current state {self._state}")

            self.go_next()

            if self.go_curr() == 0:
                self.go_state(State._0)
            elif self.go_curr() == 1:
                self.go_state(State._1)
            else:
                self.go_state(State.End)

        elif self._state == State._0:
            print(f"current state {self._state}")

            self.go_next()

            if self.go_curr() == 0:
                self.go_state(State._00)
            elif self.go_curr() == 1:
                self.go_state(State._1)
            else:
                self.go_state(State.End)

        elif self._state == State._1:
            print(f"current state {self._state}")

            self.go_next()

            if self.go_curr() == 0:
                self.go_state(State._0)
            elif self.go_curr() == 1:
                self.go_state(State._1)
            else:
                self.go_state(State.End)

        elif self._state == State._00:
            print(f"current state {self._state}")

            self.go_next()

            if self.go_curr() == 0:
                self.go_prev()
                self.go_state(State.Action)
            elif self.go_curr() == 1:
                self.go_state(State._1)
            else:
                self.go_state(State.End)

        elif self._state == State.Action:
            print(f"current state {self._state}")

            self._data[self._index] = 1
            self.go_state(State._1)

        elif self._state == State.End:
            print(f"state end, index: {self._index}, length: {self._length}")

            self.stop()
        else:
            pass

        return self._off

    def run(self) -> None:
        self._off = False
        while (not self._off):
            self.detail()
            self._off = self.update()
        pass

    def stop(self) -> None:
        self._off = True

    pass


def RRMSE(y_train: np.ndarray, y_pred: np.ndarray) -> float:
    n = y_train.shape[0]
    y_mean = np.mean(y_train)
    x_1 = np.sqrt((1 / n) * np.sum(np.power(y_train - y_pred, 2)))
    x_2 = np.sqrt((1 / (n - 1)) * np.sum(np.power(y_train - y_mean, 2)))
    return x_1 / x_2


def first(l: list):
    yield l[0]
    pass


def rest(l: list):
    yield l[1:]
    pass


def num_list(l: list):
    pass


def main(argument: list) -> int:
    # input_array_1 = [1, 0, 0, 0, 1]
    # answer_list_1 = [1, 0, 1, 0, 1]
    # input_array_2 = [0, 0, 0, 0, 0]
    # answer_list_2 = [0, 1, 0, 1, 0]
    # m = Machine(input_array_2)
    # m.run()

    # a = np.array(input_array_1)
    # b = np.array(answer_list_1)

    # print(RRMSE(a, b))

    # print(b - np.mean(a))

    # L = [1, "2", [3, "4", 5, ["6", 7, ["8", 9]]], 10, 1.0]
    # a = first(L)
    # print(a)

    # l_1 = [0.0000001,  2.010, 3.100]
    # l_2 = [0.9999999, -2.001, 3.001]
    # l_3 = [1.0000000,  0.009, 6.101]

    # j = 0
    # for i in l_1:
    #     l_2[j] += i
    #     j += 1

    # print(l_2)
    # print((l_1 + l_2) == l_3)

    pi = 3.14159265358979323846
    e =  2.71828182845904523536
    val = pi * e
    vec = [val] * 10
    print(vec)
    vec = list(map(lambda x: x * 2, vec))
    print(vec)
    vec = list(map(lambda x: x / 2, vec))
    print(vec)
    vec = list(map(lambda x: x * e, vec))
    print(vec)
    vec = list(map(lambda x: x / pi, vec))
    print(vec)

    cal = list(map(lambda x: x + x, vec))
    print(cal)
    # for i in range(500000, 1000000):
    #     vec[i] = e
    array_1 = np.array(cal)
    print(np.linalg.norm(array_1, 2))


    return 0


if __name__ == "__main__":
    main(sys.argv)
