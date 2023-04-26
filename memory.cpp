#include "memory.hpp"
void memorytest()
{
    FILE* file = fopen("java.bin","rw");
    long* p = new long[8];
    for (int i = 0; i < 8; i++)
    {
        p[i]= hexOfv;
        fwrite(&p[i],sizeof(long),1,file);
        cout << p[i] << endl;
    }
    
    bool greaterThanHexOfv = false;
    for (int i = 0; i < 8; i++)
    {
        if (p[i] > hexOfv)
        {
            greaterThanHexOfv = true;
            break;
        }
    }
    
    if (greaterThanHexOfv)
    {
        fclose(file)
        delete[] p;
        p = nullptr;
    }
}

int main()
{
    memorytest();
    return 0;
}