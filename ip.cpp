
#include <iostream>
#include <string>
using namespace std;


unsigned int toNumber(const char* ip)
{
	unsigned int re = 0;
	unsigned char tmp = 0;

	//O(n)
	while (true)
	{
		if (*ip != '\0'&&*ip != '.')
		{
			tmp = tmp * 10 + *ip - '0';
		}
		else
		{
			re = (re << 8) + tmp;
			
			if (*ip == '\0')
			{
				break;
			}
			tmp = 0;
		}
		ip++;
	}
	return re;
}

string toString(unsigned int ip)
{  

    string str = "";  
    for (int i=0;i<4;i++)  
    {  
        unsigned int tmp=(ip>>((3-i)*8))&0xFF;  

        char chBuf[8] = "";
		_itoa_s(tmp, chBuf, 10);//int2str
        str += chBuf;

        if (i < 3)
        {
            str += '.';
        }
    }  

    return str;  
}



int main()
{
	const char *s = "128.0.3.193";

	cout << toNumber(s) << endl;

	cout << toString(toNumber(s)) << endl;

	system("pause");
	return 0;

}