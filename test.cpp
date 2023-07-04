#include <vector>
#include <iostream>

using namespace std;

int main(){

vector<vector<int> > wall_arr;

for (int i = 0; i < 5; i++)
    {
        vector<int> row(5, 0);
        wall_arr.push_back(row);
    }

wall_arr[3][2] = 1;

for (int k = 0; k < 5; k++)
{
    for (int j = 0; j < 5; j++)
    {
        cout << wall_arr[k][j] << " ";
    }
    cout << endl;
    
}

return 0;

}
