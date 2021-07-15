#include <iostream>
#include "Zlab06.h"
int main()
{
    Kwadrat kwadrat("Kwadrek",4);
    Kwadrat & refDoKwadrat = kwadrat;
    double r0 = refDoKwadrat.promienKolaWgPola();
    double r1 = refDoKwadrat.promenOkreguWgObwodu();

    cout << "ro=" << r0 << endl
            << "r1=" << r1 << endl;

    return 0;
}