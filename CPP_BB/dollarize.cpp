/*
class MoneyFmt(object):
    def __init__(self, value = 0.0):
        self.value = float(value)
    
    def update(self, value = None):
        """
        Method that checks if value is updated with valid value
        """
        try:
            self.value = float(value)
        except ValueError:
            pass
            
    def __nonzero__(self):
        """
        Checks if value is nonzero
        """
        if self.value != 0:
            return True
        return False
    
    def __repr__(self):
        """
        returns a string that is a printable representation of the object
        """
        return repr(self.value)
    
    def __str__(self):
    """
    Magic Method that allows object to be printed
    Making use of str.format
    """
        if self.value < 0:
            self.value *= -1
            return '-${:,.2f}'.format(self.value)
        return'${:,.2f}'.format(self.value)

cash = MoneyFmt("123")
print cash
cash.update(-155)
print cash
print cash.__nonzero__()
cash.update(1234567.89)
print cash
*/

#include <iostream>

using namespace std;

//CLASS DECLARATION GOES HERE

int main()
{
    return 0;
}

//CLASS DEF GOES HERE