#ifndef DISJOINTSET_H
#define DISJOINTSET_H


class DisjointSet
{
public:
    DisjointSet(int n)
    {
        numberOfElement = n;
        parentId = new int[n];
        sizeArr = new int[n];

        for (int i = 0; i < n; i++)
        {
            parentId[i] = i;
            sizeArr[i] = 1;
        }
    };

    int findParrent(int p)
    {
        int root = p;
        while (root != parentId[root])
            root = parentId[root];

        // path compression
        while (p != root)
        {
            int next = parentId[p];
            parentId[p] = root;
            p = next;
        }

        return root;
    }

    bool connected(int p, int q)
    {
        return findParrent(p) == findParrent(q);
    }

    void marge(int p, int q)
    {

        int root1 = findParrent(p);
        int root2 = findParrent(q);

        if(root1 == root2)
        {
            return;
        }
        else if (sizeArr[root1] < sizeArr[root2])
        {
            sizeArr[root2] += sizeArr[root1];
            parentId[root1] = root2;
        }
        else
        {
            sizeArr[root1] += sizeArr[root2];
            parentId[root2] = root1;
        }
    };

protected:

private:
    int numberOfElement;
    int *parentId;
    int *sizeArr;
};

#endif // DISJOINTSET_H
