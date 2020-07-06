#ifndef RESOURCES_H_
#define RESOURCES_H_
#include <string>
using namespace std;

//Resources

class Resources {
private:
	int m_coal;
	int m_oil;
	int m_garbage;
	int m_uranium;
	int m_price;

public:
	Resources();
	Resources(int c, int o, int g, int u, int p);
	//set methods
	void setCoal(int c);
	void setOil(int o);
	void setGarbage(int g);
	void setUranium(int u);
	void setPrice(int p);
	//get methods
	int getCoal(void);
	int getOil(void);
	int getGarbage(void);
	int getUranium(void);
	int getPrice(void);
		//add methods
	void addCoal(int c);
	void addOil(int o);
	void addGarbage(int g);
	void addUranium(int u);
	//print data
	string toString();
};



#endif // !RESOURCES_H_
