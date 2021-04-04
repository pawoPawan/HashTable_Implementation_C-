//------    HASH MAPPING

// --------------------- REQUIREMENTS
// 1. hash function --> to generate index of key from user information
// 2. collision handling --> handle two data poits that map to same index
// 3. put --> add data to a hash map ? in O(1) time
// 4. get --> retrieve data fron a hash map ? in O(1) time
// ------------------

// Put O(1) time --> hashfunction --> collision handling --> hashmap(storing data in an array with massive amount of data) --> get O(1) time

#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

typedef long int li;
class Hashmap;

class Hashmap
{
private:
    // Declare the size of container or range of idx
    int _BucketSize;
    // data is stored in form of list
    list<int> *_Hashtable;
public:
    // Default constructor
    //Hashmap():_BucketSize(0){};
    // parametic constructor
    Hashmap(int BSize):_BucketSize(BSize),_Hashtable(new list<int>[_BucketSize]){};
    // Destructor
    ~Hashmap(){delete [] _Hashtable;};
    // hash Function
    int Hashfunc(li no);
    // ----Key functions of hash map
    // Append
    void Append(int contno);
    // Deletes
    void Delete(int contno);
    // Get all data
    void Display();

};

// ---------HASH TABLE FUNCTION DEFINITIONS-----------
int Hashmap::Hashfunc(li no)
{
    int key = no%_BucketSize;
    return key;
}

void Hashmap::Append(int contno)
{
    // compute idx  from hash function
    int idx = Hashfunc(contno);
    _Hashtable[idx].push_back(contno);
}

void Hashmap::Delete(int contno)
{
    // get idx from hash function
    int idx = Hashfunc(contno);
    // search contact no from list at that idx
    list<int>::iterator itr;
    for(itr = _Hashtable[idx].begin(); itr != _Hashtable[idx].end(); itr++)
        if(*itr == contno)break;
    
    // if found, delete from table
    if(itr != _Hashtable[idx].end())
        _Hashtable[idx].erase(itr);
}

void Hashmap::Display()
{
    for (int i = 0; i < _BucketSize; i++) {
      cout << i;
        list<int>::iterator itr;
        for (itr = _Hashtable[i].begin(); itr != _Hashtable[i].end(); itr++)
        cout << " --> " << *itr;
      cout << endl;
    }
}

// ----   MAIN FUNCTION

int main()
{
    vector<int> vectarr = {15, 11, 27, 8, 12,11,12,15,13,17,18,19,21,16,33};
    
    // BucketSize is 5
    Hashmap hashtable(5);
    
    for(int i = 0; i < vectarr.size(); i++)
        hashtable.Append(vectarr[i]);
    
    // Display
    hashtable.Display();
    
    return 0;
}
