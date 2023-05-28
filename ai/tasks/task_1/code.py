import copy

# Παραλλαγές κώδικα από τον @ice21390179

import sys
from typing import Any

sys.setrecursionlimit(10**6)


# μεταβλητές Τύπων μεταβλητών για convenience
grid = list[list[list[str]]]

DEBUG = False


def can_eat(state: grid) -> int | None:
    for i in range(len(state)):
        for j in range(len(state[0])):
            if state[i][j][0] == "p" and state[i][j][1] == "f":
                return 1


def can_move_up(state: grid) -> bool:
    for i in range(len(state)):
        for j in range(len(state[0])):
            if state[i][j][0] == "p":
                if i == 0:  # Player is in top row
                    return False
                else:
                    return True


def can_move_down(state: grid) -> bool:
    for i in range(len(state)):
        for j in range(len(state[0])):
            if state[i][j][0] == "p":
                if i == len(state) - 1:  # Player is in bottom row
                    return False
                else:
                    return True


def can_move_right(state: grid) -> bool:
    return not state[len(state) - 1][0][0] == "p"


def can_move_left(state: grid) -> bool:
    return not state[0][0][0] == "p"


def eat(state: grid) -> grid | None:
    if can_eat(state):
        for i in range(len(state)):
            for j in range(len(state[0])):
                if state[i][j][0] == "p" and state[i][j][1] == "f":
                    state[i][j][1] = ""
                    return state
    else:
        return None


def move_right(state: grid) -> grid | None:
    if can_move_right(state):
        for i in range(len(state)):
            for j in range(len(state[0])):
                if state[i][j][0] == "p":
                    state[i][j][0] = ""
                    if j == len(state[0]) - 1:
                        return None
                    state[i][j + 1][0] = "p"
                    return state
    else:
        return None


def move_left(state: grid) -> grid | None:
    if can_move_left(state):
        for i in range(len(state)):
            for j in range(len(state[0])):
                if state[i][j][0] == "p":
                    state[i][j][0] = ""
                    if j == 0:
                        return None
                    state[i][j - 1][0] = "p"
                    return state
    else:
        return None


def move_down(state: grid) -> grid | None:
    if can_move_down(state):
        for i in range(len(state)):
            for j in range(len(state[0])):
                if state[i][j][0] == "p":
                    state[i][j][0] = ""
                    if i == len(state) - 1:
                        return None
                    state[i + 1][j][0] = "p"
                    return state
    else:
        return None


def move_up(state: grid) -> grid | None:
    if can_move_up(state):
        for i in range(len(state)):
            for j in range(len(state[0])):
                if state[i][j][0] == "p":
                    state[i][j][0] = ""
                    if i == 0:
                        return None
                    state[i - 1][j][0] = "p"
                    return state
    else:
        return None


def find_children(state: grid) -> list[grid]:
    children: list[grid] = []

    # Δεξιά
    right_state = copy.deepcopy(state)
    child_right = move_right(right_state)

    # Αριστερά
    left_state = copy.deepcopy(state)
    child_left = move_left(left_state)

    # Πάνω
    up_state = copy.deepcopy(state)
    child_up = move_up(up_state)

    # Κάτω
    down_state = copy.deepcopy(state)
    child_down = move_down(down_state)

    eat_state = copy.deepcopy(state)
    child_eat = eat(eat_state)

    if child_right is not None:
        children.append(child_right)

    if child_left is not None:
        children.append(child_left)

    if child_down is not None:
        children.append(child_down)

    if child_up is not None:
        children.append(child_up)

    if child_eat is not None:
        children.append(child_eat)

    return children


def make_front(state: grid) -> list[grid]:
    """
    Αρχικοποίηση μετώπου
    """
    return [state]


def expand_front(front: list[grid], method: str) -> list[grid]:
    """
    Eπέκταση μετώπου
    """
    if method == "DFS":
        if front:
            node = front.pop(0)
            for child in find_children(node):
                front.insert(0, child)

    elif method == "BFS":
        if front:
            node = front.pop(0)
            for child in find_children(node):
                front.append(child)
    return front


def make_queue(state: grid) -> list[list[grid]]:
    """
    Επέκταση ουράς
    """
    return [[state]]


def extend_queue(queue: list[list[grid]], method: str) -> list[list[grid]]:
    queue_copy: list[list[grid]] = []

    if method == "DFS":
        if DEBUG:
            print(queue)

        node = queue.pop(0)
        queue_copy = copy.deepcopy(queue)
        children = find_children(node[-1])
        for child in children:
            path = copy.deepcopy(node)
            path.append(child)
            queue_copy.insert(0, path)

    elif method == "BFS":
        if DEBUG:
            print(queue)

        node = queue.pop(0)
        queue_copy = copy.deepcopy(queue)
        children = find_children(node[-1])
        for child in children:
            path = copy.deepcopy(node)
            path.append(child)
            queue_copy.append(path)

    return queue_copy


def find_solution(
    front: list[grid],
    queue: list[list[grid]],
    closed: list[Any],
    goal: grid,
    method: str,
):
    """
    Βασική αναδρομική συνάρτηση για δημιουργία δέντρου αναζήτησης
    (αναδρομική επέκταση δέντρου)
    """

    if not front:
        print("_NO_SOLUTION_FOUND_")

    elif front[0] in closed:
        if queue:
            new_front = copy.deepcopy(front)
            new_front.pop(0)
            new_queue = copy.deepcopy(queue)
            new_queue.pop(0)
            find_solution(new_front, new_queue, closed, goal, method)

    elif front[0] == goal:
        print("#####################################")
        print("_GOAL_FOUND_")
        print(queue[0])
        print("#####################################")

    else:
        closed.append(front[0])
        front_copy = copy.deepcopy(front)
        front_children = expand_front(front_copy, method)
        queue_copy = copy.deepcopy(queue)
        queue_children = extend_queue(queue_copy, method)
        closed_copy = copy.deepcopy(closed)
        find_solution(
            front_children, queue_children, closed_copy, goal, method
        )


def main():
    """
    ** Κύριο πρόγραμμα
    """

    global DEBUG

    initial_state: grid = [
        [["p", ""], ["", ""], ["", "f"], ["", "f"]],
        [["", "f"], ["", ""], ["", ""], ["", ""]],
        [["", ""], ["", ""], ["", ""], ["", ""]],
    ]
    goal: grid = [
        [["", ""], ["", ""], ["", ""], ["", ""]],
        [["p", ""], ["", ""], ["", ""], ["", ""]],
        [["", ""], ["", ""], ["", ""], ["", ""]],
    ]

    method: str = input("Επιλογή Αλγορίθμου DFS/BFS (Default: DFS):")
    method = "".join(method.split(" "))
    method = method.upper()

    if method == "":
        method = "DFS"

    DEBUG = input("Ενεργοποίση παρακολούθησης ουράς (Default: False) [Y/N]: ")
    DEBUG = DEBUG.upper()
    if DEBUG == "Y":
        DEBUG = True
    else:
        DEBUG = False

    fruits_n: int = int(input("Δώσε αριθμό για τα φρουτάκια: "))
    # Έλεγχος Ορθότητας
    if fruits_n <= 0:
        fruits_n = 1

    print("____BEGIN__SEARCHING____")
    for _ in range(fruits_n):
        find_solution(
            make_front(initial_state),
            make_queue(initial_state),
            [],
            goal,
            method,
        )


if __name__ == "__main__":
    main()
