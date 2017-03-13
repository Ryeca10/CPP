#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

class Package
{
    
   public:
       
      Package (const char *, const char *, const char *, float, float, bool, bool, int, int, int);
       
       
       virtual float CalcPay() const=0;
       virtual float CalcRate() const;
       virtual void Print() const;
    

   private:
        char  *name;
        char  *address1;
        char  *address2;
        float  cost;
        float  afterDisc;
        bool   overNight;
        bool   insurance;
        int    itemsNum;
        int    orderDate;
        int    arrivalDate;

};

Package :: Package (const char *n , const char *a1, const char *a2, float c, float ad, bool on, bool ins,int items, int order, int arrival=0)
{
    name = new char[strlen(n) + 1];
    strcpy(name,n);
    address1 = new char[ strlen(a1) + 1];
    strcpy(address1,a1);
    address2 = new char[ strlen(a2) + 1];
    strcpy(address2,a2);
    orderDate = order;
    cost = c;
    afterDisc = ad;
    overNight = on;
    insurance = ins;
    itemsNum = items;
    orderDate = order;
    arrivalDate = arrival;
    

    if(overNight)
        arrivalDate = ++orderDate;
    else
        arrivalDate = orderDate+3;
}

float Package :: CalcPay() const
{
    float costP = itemsNum * cost;
    
    if (overNight)
        costP += 9.99;

    if (insurance)
        costP *= 1.03;
    
    return costP;
    
}  


float Package :: CalcRate() const
{
        float costp = CalcPay();
        float discRate;
    if (costp <= 50)
        discRate = 2.4;
    else if ( costp <= 100)
        discRate = 2.9;
    else if ( costp <= 250) 
        discRate = 4.1;
    else 
        discRate = 4.8;
       
    return costp - costp*discRate/100;
}


void Package :: Print() const
{
	cout << name << "            " << "Expected Arrival date: "  << arrivalDate <<endl;
        cout << address1 << endl;
        cout << address2 << endl;
}


class Books : public Package
{
        public: 
            
        Books(const char * , const char *, const char *, 
                      float, float, bool, bool,int, int, int);
        
        virtual float CalcPay() const ;
        virtual float CalcRate() const;
        virtual void Print() const ;
        
        private:
            float cost;
            int itemsNum;
            bool overNight;
            bool insurance;

};


Books :: Books(const char *name, const char *address1, const char *address2, 
                float costB, float afterDisc, bool overNightB, bool insuranceB,
                int items, int orderDate, int arrivalDate)

       : Package(name, address1, address2, costB, afterDisc, overNightB, 
                insuranceB, items, orderDate, arrivalDate)
{
    cost = costB;
    itemsNum = items;
    overNight = overNightB;
    insurance = insuranceB;
}

void Books :: Print() const
{
    Package :: Print();
    cout << endl;
    cout << itemsNum << " books ordered: " << ", Shipping cost is: $" << itemsNum*cost;
    
    if (overNight)
    {
        cout << ", Overnight is $9.99 ";
    }
    if (insurance)
    {
        cout << ", Insurance is requested." << endl;
    }
    else 
    {
        cout << ", No insurance specified. " << endl;
    }
    
    cout << "Total cost is: " << CalcPay() << endl ;
    cout << "Total cost after discount is: " << CalcRate() << endl;
    cout << "_______________________________________" << endl;
    cout << endl << endl;
}

float Books :: CalcPay() const
{
    float costP = itemsNum * cost;
    
    if (overNight)
        costP += 9.99;

    if (insurance)
        costP *= 1.03;
    
    return costP;
} 

float Books :: CalcRate() const
{
        float costp = CalcPay();
        float discRate;
    if (costp <= 50)
        discRate = 2.4;
    else if ( costp <= 100)
        discRate = 2.9;
    else if ( costp <= 250) 
        discRate = 4.1;
    else 
        discRate = 4.8;
       
    return (costp - costp*discRate/100);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

class Phones : public Package
{
        public: Phones(const char * , const char *, const char *, 
                      float, bool, bool,int, int, int, bool , int, bool);
        
        virtual float CalcPay() const ;
        virtual float CalcRate() const;
        virtual void Print() const ;
        
        private:
            float cost;
            int itemsNum;
            bool overNight;
            bool insurance;
            bool virusSoftware;
            int numVirus;
            bool unlimited;

};

Phones :: Phones(const char *name, const char *address1, const char *address2, 
                float costB, bool overNightB, bool insuranceB,
                int items, int orderDate, int arrivalDate, bool vss, int nv, bool ul)

       : Package(name, address1, address2, costB, overNightB, 
                insuranceB, items, orderDate, arrivalDate)
{
    cost = costB;
    itemsNum = items;
    overNight = overNightB;
    insurance = insuranceB;
     virusSoftware = vss;
     numVirus = nv;
     unlimited = ul;
}

void Phones :: Print() const
{
    Package :: Print();
    cout << endl;
    cout << itemsNum << " phones ordered: " << ", Shipping cost is: $" << itemsNum*cost;
    
    if (overNight)
    {
        cout << ", Overnight is $9.99 ";
    }
    if (insurance)
    {
        cout << ", Insurance is requested." << endl;
    }
    else 
    {
        cout << ", No insurance specified. " << endl;
    }
    
    cout << "Total cost is: " << CalcPay() << endl ;
    cout << "Total cost after discount is: " << CalcRate() << endl;
    cout << "_______________________________________" << endl;
    cout << endl << endl;
    
}

float Phones :: CalcPay() const
{
    float costP = itemsNum * cost;
    
    if (overNight)
        costP += 25.00;

    if (insurance)
        costP = costP + costP * 0.11;
    
    if(virusSoftware)
        costP += numVirus*19.99;
          
    if(unlimited)
        costP += itemsNum*99.99;
    
    return costP;
} 

float Phones :: CalcRate() const
{
        float costp = CalcPay();
        float discRate;
    if (costp <= 50)
        discRate = 2.4;
    else if ( costp <= 100)
        discRate = 2.9;
    else if ( costp <= 250) 
        discRate = 4.1;
    else 
        discRate = 4.8;
       
    return costp - costp*discRate/100;
}

//////////////////////////////////////////////////////////////////////////////////////////////

class Drinks : public Package
{
        public: Drinks(const char * , const char *,const char *, 
                      float, bool, bool,int, int, int, bool , bool);
        
        virtual float CalcPay() const ;
        virtual float CalcRate() const ;
        virtual void Print() const ;
        
        private:
            float cost;
            int itemsNum;
            bool overNight;
            bool insurance;
            bool refridge;
            bool alchol;

};

Drinks :: Drinks(const char *name, const char *address1, const char *address2, 
                float costB, bool overNightB, bool insuranceB,
                int items, int orderDate, int arrivalDate, bool rfg, bool alc)

       : Package(name, address1, address2, costB, overNightB, 
                insuranceB, items, orderDate, arrivalDate)
{
    cost = costB;
    itemsNum = items;
    overNight = overNightB;
    insurance = insuranceB;
    refridge = rfg;
    alchol = alc;
}

void Drinks :: Print() const
{
    Package :: Print();
    cout << endl;
    cout << itemsNum << " ounce of drink ordered: " << ", Shipping cost is: $" << itemsNum*cost;
    
    if (overNight)
    {
        cout << ", Overnight is $9.99 ";
    }
    if (insurance)
    {
        cout << ", Insurance is requested." << endl;
    }
    else 
    {
        cout << ", No insurance specified. " << endl;
    }
    
    cout << "Total cost is: " << CalcPay() << endl ;
    cout << "Total cost after discount is: " << CalcRate() << endl;
    cout << "_______________________________________" << endl;
    cout << endl << endl;
}

float Drinks :: CalcPay() const
{
   float costP = itemsNum * cost;
    
    if (overNight)
        costP += 18.00;

    if (insurance)
        costP = costP + costP * 0.08;
    
    if(refridge)
        costP += itemsNum*0.12;
          
    if(alchol)
        costP += itemsNum*1.19;
    
    return costP;
} 

float Drinks :: CalcRate() const
{
        float costp = CalcPay();
        float discRate;
    if (costp <= 50)
        discRate = 2.4;
    else if ( costp <= 100)
        discRate = 2.9;
    else if ( costp <= 250) 
        discRate = 4.1;
    else 
        discRate = 4.8;
       
    return costp - costp*discRate/100;
}

//////////////////////////////////////////////////////////////////////////////////////////////



class Laptops : public Package
{
        public: Laptops(const char * , const char *, const char *, 
                      float , bool, bool,int, int, int, bool , bool);
        
        virtual float CalcPay() const ;
        virtual float CalcRate() const ;
        virtual void Print() const ;
        
        private:
            float cost;
            int itemsNum;
            bool overNight;
            bool insurance;
            bool wifi;
            bool moreMemory;

};

Laptops :: Laptops(const char *name, const char *address1, const char *address2, 
                float costB,  bool overNightB, bool insuranceB,
                int items, int orderDate, int arrivalDate, bool wireless, bool mem)

       : Package(name, address1, address2, costB, overNightB, 
                insuranceB, items, orderDate, arrivalDate)
{
    cost = costB;
    itemsNum = items;
    overNight = overNightB;
    insurance = insuranceB;
    wifi = wireless;
    moreMemory = mem;
}

void Laptops :: Print() const
{
    Package :: Print();
    cout << endl;
    cout << itemsNum << " laptops ordered: " << ", Shipping cost is: $" << itemsNum*cost;
    
    if (overNight)
    {
        cout << ", Overnight is $9.99 ";
    }
    if (insurance)
    {
        cout << ", Insurance is requested." << endl;
    }
    else 
    {
        cout << ", No insurance specified. " << endl;
    }
    
    cout << "Total cost is: " << CalcPay() << endl ;
    cout << "Total cost after discount is: " << CalcRate() << endl;
    cout << "_______________________________________" << endl;
}

float Laptops :: CalcPay() const
{
    int costP = cost;
    costP = itemsNum * 0.45;
    
    if (overNight)
        costP += 18.00;

    if (insurance)
        costP = costP + costP * 0.11;
    
    if(wifi)
        costP += itemsNum*55.00;
          
    if(moreMemory)
        costP += itemsNum*65.00;
    
    return costP;
} 

float Laptops :: CalcRate() const
{
        float costp = CalcPay();
        float discRate;
    if (costp <= 50)
        discRate = 2.4;
    else if ( costp <= 100)
        discRate = 2.9;
    else if ( costp <= 250) 
        discRate = 4.1;
    else 
        discRate = 4.8;
       
    return costp - costp*discRate/100;
}

//////////////////////////////////////////////////////////////////////////////////////////////




int main()
{
    cout << fixed << showpoint << setprecision(2);
    
    Package *ptr1;
    ptr1 = new Books("Joe Blow" , "14 SomewhereLane", "Irvine, CA, 92656", 2.47, 3.00, true, true, 5, 14, 15);
    ptr1->Print();
    
    Package *ptr2;
    ptr2 = new Phones( "Jow Blow",  "14 SomewhereLane", "Irvine, CA, 92656", 19.99, false ,true, 3, 12, 16,true,4,true);
    ptr2->Print();
    
    Package *ptr3;
    ptr3 = new Drinks("Jow Blow",  "14 SomewhereLane", "Irvine, CA, 92656" , 0.45, false, false, 100, 3, 6,true, true);
   
    ptr3->Print();
    
    Package *ptr4;
    
    ptr4 = new Laptops("Jow Blow",  "14 SomewhereLane", "Irvine, CA, 92656", 524.12, true, true, 1, 1, 2, true, false);
    ptr4->Print();
    
    return 0;
}