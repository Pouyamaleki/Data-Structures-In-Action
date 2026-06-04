#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

using namespace std;

// custome hash
template <typename KEY>
struct HashFunction
{
    size_t operator()(const KEY &key) const
    {
        return static_cast<size_t>(key);
    }
};

// hash for string
template <>
struct HashFunction<string>
{
    size_t operator()(const string &key) const
    {
        size_t hash = 0;
        for (char c : key)
        {
            hash = hash * 31 + c;
        }
        return hash;
    }
};

// custome map
template <typename KEY, typename VALUE>
class MyMap
{
private:
    vector<list<pair<KEY, VALUE>>> buckets;
    int elementCount;

    size_t getBucketIndex(const KEY &key) const
    {
        HashFunction<KEY> hash;
        return hash(key) % buckets.size();
    }

public:
    // constructor
    MyMap(int size = 10)
    {
        buckets.resize(size);
        elementCount = 0;
    }

    // add key value
    void insert(const KEY &key, const VALUE &value)
    {
        int index = getBucketIndex(key);

        // check if the key is already in the system or no
        for (auto &pair : buckets[index])
        {
            if (pair.first == key)
            {
                return;
            }
        }

        // add new Pair
        buckets[index].push_back({key, value});
        elementCount++;
    }

    // fina a value with the key
    VALUE find(const KEY &key) const
    {
        int index = getBucketIndex(key);

        for (const auto &pair : buckets[index])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }

        throw runtime_error("key_error");
    }
};

// main function
int main()
{
    try
    {
        MyMap<string, int> myMap;

        // add three item
        myMap.insert("Mohamad", 20);
        myMap.insert("Pouya", 25);
        myMap.insert("x", 22);

        // find the vlues
        cout << "Mohamad Age: " << myMap.find("Mohamad") << endl;
        cout << "Pouya Age: " << myMap.find("Pouya") << endl;
        cout << "x Age: " << myMap.find("x") << endl;

        // excception error
        cout << "Ahmad Age: " << myMap.find("Ahmad") << endl;
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}