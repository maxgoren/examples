#include <iostream>
#include <vector>
#include <list>
#include <tuple>
using namespace std;

class HashTable {
    private:
    typedef std::tuple<bool, string, int> htret;
    typedef unsigned int uint;
    int M; //default is 101, should always be a prime number
    int numRecords;
    typedef std::pair<string, string> record;
    std::vector<std::list<record> > table;
    
    public:
    HashTable(int sz = 101) 
    {
        M = sz;
        numRecords = 0;
        table.resize(M);
    }
    
    uint horner(string key);
    void    put(string key, string value);
    htret   get(string key);
    void remove(string key);
    int    size() { return numRecords; }
    bool  empty() { return numRecords == 0; }
    string operator[](const string& key) {
        auto [flag, ret, pos] = get(key);
        return ret;
    }
};

unsigned int HashTable::horner(string key)
{
   int hash = 0;
   for (char c : key)
   {
      hash = (64*hash + c) % M;
   }
   return hash;
}

void HashTable::put(string key, string value)
{
    unsigned int mapped = horner(key);
    table[mapped].push_front(make_pair(key,value));
    numRecords++;
}

std::tuple<bool, string, int> HashTable::get(string key)
{
   bool found = false;
   unsigned int mapped = horner(key);
   unsigned int position = 0;
   cout<<"Fetching data associated with: "<<key<<endl;
   for (auto rec : table[mapped])
   {
    if (rec.first == key)
    {
      return make_tuple(true, rec.second, position);
    }
    position++;
   }
   return make_tuple(false, key + ": not found.", -1);
}

void HashTable::remove(string key)
{
    auto [found, result, pos] = get(key);
    if (found)
    {
        auto itr = table[horner(key)].begin();
        advance(itr, pos);
        table[horner(key)].erase(itr);
    }
}

int main(int argc, char *argv[])
{
    HashTable myHT(101);
    myHT.put("Robert Sedgewick", "Algorithms in C++");
    myHT.put("Clifford A. Shaffer", "Data Structures & Algorithms Analysis in Java");
    myHT.put("Larry Wall", "Programming Perl");
    myHT.put("Randall Munroe", "xkcd");
    myHT.put("Donald Knuth", "The art of computer programming");
    cout<<myHT["Windows Programming"]<<endl;
    cout<<myHT["Larry Wall"]<<endl;
    myHT.remove("Larry Wall");
    cout<<myHT["Larry Wall"]<<endl;
    return 0;
}