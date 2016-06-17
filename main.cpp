#define ARR_SIZE 1000
#include<stdio.h>
#include <vector>
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

vector< vector<int> > points_comb;





/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size);

/* The function prints all combinations of numbers 1, 2, ...MAX_POINT
   that sum up to n.
   i is used in recursion keep track of index in arr[] where next
   element is to be added. Initital value of i must be passed as 0 */
void printCompositions(int n, int i, int r)
{

  /* array must be static as we want to keep track
   of values stored in arr[] using current calls of
   printCompositions() in function call stack*/
  static int arr[ARR_SIZE];

  if (n == 0 && i == r)
  {
    printArray(arr, i);
  }
  else if(n > 0)
  {
    int k;
    int MAX_POINT = n;
    for (k = 1; k <= MAX_POINT; k++)
    {
      arr[i]= k;
      printCompositions(n-k, i+1, r);
    }
  }
}

/* UTILITY FUNCTIONS */
/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size)
{

  int i;
  vector<int> vec;

  for (i = 0; i < arr_size; i++){
    //printf("%d ", arr[i]);

   vec.push_back(arr[i]);
  }

 points_comb.push_back(vec); // Pushing it to the final vector
}

// Subset function
// Global variable to add lists

vector< list<int> > vec1;
vector< list<int> > vec2;
vector< list<int> > vec3;


// Subset function
void print( list<int> l){

    for(list<int>::iterator it=l.begin(); it!=l.end() ; ++it){

      //cout << " " << *it;

    }

    vec1.push_back(l);

    //cout<<"   ";

}

void subset(vector<int> arr, int size, int left, int index, list<int> &l){
    if(left==0){
        print(l);
        return;
    }
    for(int i=index; i<size;i++){
        l.push_back(arr[i]);
        subset(arr, size, left-1, i+1, l);
        l.pop_back();

    }

}

// Subset function
void print_new( list<int> l){

    for(list<int>::iterator it=l.begin(); it!=l.end() ; ++it){

      //cout << " " << *it;

    }



    vec2.push_back(l);

    //cout<<"   ";

}

void subset_new(vector<int> arr, int size, int left, int index, list<int> &l){
    if(left==0){
        print_new(l);
        return;
    }
    for(int i=index; i<size;i++){
        l.push_back(arr[i]);
        subset_new(arr, size, left-1, i+1, l);
        l.pop_back();

    }

}

// Subset function
void print_new_1( list<int> l){

    for(list<int>::iterator it=l.begin(); it!=l.end() ; ++it){

      //cout << " " << *it;

    }



    vec2.push_back(l);

    //cout<<"   ";

}

void subset_new_1(vector<int> arr, int size, int left, int index, list<int> &l){
    if(left==0){
        print_new_1(l);
        return;
    }
    for(int i=index; i<size;i++){
        l.push_back(arr[i]);
        subset_new_1(arr, size, left-1, i+1, l);
        l.pop_back();

    }

}




// Helper functions

// FUnction to print a vector
 void print_vec(vector<int> v){

     for(int i=0; i< v.size(); i++){

        cout<< v[i]<<" ";
     }

     cout<<endl;

 }

//vector<iteration> clusters;

// Final vector that contains all the points

vector< vector <list<int> > > cluster_points;

vector<list <int> > cluster_points_vector;


/* Driver function to test above functions */
int main()
{
  int n, r;

  n = 9;
  r = 4;

  // cin n later

  printCompositions(n, 0, r);

  cout<<"\nThe combination of points vector is: \n";

  //Checking that the points comb vector is correct.


  // THe combinations are correct.

     int size = 9;
     int left = 4;

  vector<int> arr;

  for(int i=0; i< size; i++){
    arr.push_back(i+1);
  }

  int index = 0;

  list<int> l;

  vec1.clear();

  subset( arr, size, left, index, l);

  cout<<"vec1 size is: "<<vec1.size()<<endl<<endl;

  cout<< "vec1 is: \n";


  for(int i=0; i< vec1.size(); i++){

    for(list<int>::iterator it = vec1[i].begin(); it != vec1[i].end(); ++it){

        cout<< *it <<" ";
    }

    cout<< endl;
  }

  cout<< "vec1 ends \n";

  // Write the second loop

  vector<int> vec_copy;


  for(int i=0; i< vec1.size(); i++){

    list<int> lt = vec1[i];
    // Iterate through the list and initial vector to remove common elements

    vec_copy.clear();

    for(int j=0; j< arr.size(); j++){

        bool present_not = true;

        for(list<int>::iterator it = lt.begin(); it != lt.end(); ++it){

            if( *it == arr[j]){
                present_not = false;
            }
        }

        if(present_not){
            vec_copy.push_back(arr[j]);
        }
    }


    list<int> lt_random;

    list<int> l;


  //  print_vec(vec_copy);

    vec2.clear();

    subset_new( vec_copy, 5, 3, 0, l);

    // vec2 will have 10 items


    // Adding the lists to a vector that will then be added to a final vector

      for(int p=0; p< vec2.size(); p++){

        cluster_points_vector.clear();

        cluster_points_vector.push_back(lt);

        cluster_points_vector.push_back(vec2[p]);

        cluster_points.push_back(cluster_points_vector);

      }

  }



  ofstream myfile;

  myfile.open("clusters.txt");


  // Print clusters vector


  for(int i=0; i<cluster_points.size(); i++){

    int ind = 1;

    for(int j=0; j< cluster_points[i].size(); j++){

        list<int> lt = cluster_points[i][j];



        cout<<"List "<< ind << ": ";
        myfile<<"List "<< ind << ": ";


        for(list<int>::iterator iter = lt.begin(); iter != lt.end(); ++iter){



            cout<< *iter <<" " ;

            myfile<< *iter <<" ";


        }

        ind++;




    }

    cout<<"\n\nvector ends \n";
    myfile<<"\n\nvector ends \n";



  }

  myfile.close();

  return 0;
}
