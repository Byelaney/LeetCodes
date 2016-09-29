/*

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)

*/

int rec_sum(const vector<NestedInteger>& nestedList, int depth)
{
    int sum = 0;
    for (int i = 0;i<nestedList.size();++i)
    {
        if (nestedList[i].isInteger())
            sum += nestedList[i].getInteger()*(depth+1);
        else
            sum += rec_sum(nestedList[i].getList(),depth+1);
    }
    return sum;
}

int depthSum(const vector<NestedInteger>& nestedList)
{
    if (nestedList.size() == 0) return 0;
    return rec_sum(nestedList, 0);
}
