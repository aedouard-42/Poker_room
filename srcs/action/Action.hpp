#ifndef ACTION_HPP
#define ACTION_HPP

enum class ActionType {
    Fold,
    Call,
    Raise,
    Check
};

struct Action {
    ActionType type;
    int amount;

    Action(ActionType type, int amount = 0) : type(type), amount(amount) {}
};

#endif
