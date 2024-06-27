#include <iostream>
using namespace std;

Class Weapon{
    public:
    Weapon(int damage_input, minimum_level_input): damage {damage_input}, minimum_level{minimum_level_input}
    {}

    private:
        int damage,
            minimum_level;
}

Class RangedWeapon{
    public:
    RangedWeapon(int damage_input, minimum_level_input; double range): Weapon()

}

int main()
{
    Weapon genericWeapon(10, 5); // first: damage, second: minimum level
    RangedWeapon bow(5, 2, 25); // first: damage, second: minimum level, third: range
    MeleeWeapon masterSword(83, 70, MeleeWeapon::Hands::two); // first: damage, second: minimum level, third: hands
    return 0;
}