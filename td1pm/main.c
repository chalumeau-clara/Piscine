#include <stdio.h>

//takes an integer action and returns whether action is between 1 and 3.
int is_action_valid(int action)
{
    return action >= 1 && action <= 3;
}

//reads an integer from the terminal and returns it.
int read_int_from_terminal(void)
{
    int value = 0;
    scanf("%d", &value);
    return value;
}

//takes no arguments and returns a valid action
int get_action(void)
{
    puts("Choose an action:");
    int action = read_int_from_terminal();
    while (!is_action_valid(action))
    {
        printf("'%d' is not a valid action\n", action);
        puts("Choose another action:");
        action = read_int_from_terminal();
    }
    return action;
}

int main(void)
{
    puts("Welcome to the world of Angel's Crypt United");
    int angel_action = get_action();
    int demon_action = get_action();

    if (angel_action == demon_action)
    {
        puts("It is a draw!");
    }
    else if (angel_action == 1 && demon_action == 3
            || angel_action == 2 && demon_action == 1
            || angel_action == 3 && demon_action == 2)
    {
        puts("The Angel won!");
    }
    else
    {
        puts("The Demon won!");
    }
}
