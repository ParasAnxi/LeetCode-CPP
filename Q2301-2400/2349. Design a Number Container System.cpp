class NumberContainers
{
    unordered_map<int, int> indToNum;
    unordered_map<int, set<int>> numToInd;

public:
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        if (indToNum.find(index) != indToNum.end())
        {
            numToInd[indToNum[index]].erase(index);
            indToNum[index] = number;
            numToInd[number].insert(index);
        }
        else
        {
            numToInd[number].insert(index);
            indToNum[index] = number;
        }
    }

    int find(int number)
    {
        if (numToInd.find(number) == numToInd.end() || numToInd[number].size() == 0)
        {
            return -1;
        }
        else
        {
            return *numToInd[number].begin();
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */