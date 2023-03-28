#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Reg,BitNo)       Reg = Reg | (1<<BitNo)
#define CLEAR_BIT(Reg,BitNo)     Reg = Reg & ~(1<<BitNo)
#define TOGGLE_BIT(Reg,BitNo)    Reg = Reg ^ (1<<BitNo)
#define GET_BIT(Reg,BitNo)       ((Reg>>BitNo) & 1)


#endif