#define ARR_SIZE 1000
#include<stdio.h>
#include <vector>
#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iterator>     // std::advance
#include <cmath>

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



    vec3.push_back(l);

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

 }

//vector<iteration> clusters;

// Final vector that contains all the points

vector< vector <list<int> > > cluster_points;

vector<list <int> > cluster_points_vector;

// Calculate coefficient of variation


// Define a class and add all the clusters to it

class final_iteration
{
public:
    vector< list<int> > vector_list;
    vector<int> combination;


};

vector<final_iteration> vector_final_iters;

// Mean and SD

//AVERAGE
double average(vector<int> v)
{      int sum=0;
       for(int i=0;i<v.size();i++)
               sum+=v[i];
       return sum/v.size();
}
//DEVIATION
double deviation(vector<int> v, double ave)
{
       double E=0;
       for(int i=0;i<v.size();i++)
               E+=(v[i] - ave)*(v[i] - ave);
       return sqrt(1/v.size()*E);
}

// Class for final calculations

class final_matrix
{
public:
    vector< list<int> > vector_list;
    vector<int> combination;
    vector<int> population;
    vector<int> distances;
    double score_cv;
    double dist_norm;
    double sum_cv_norm;


};


double DistanceNorm(vector<int> v)
{

        double norm = 0;

        for(int i=0; i<v.size(); i++){
            norm += v[i]*v[i];
        }

        return sqrt(norm);


}

double mean(vector<int> v){

    int sum =0;

    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }

    return sum/v.size();

}

double stdev(vector<int> v)
{
    double sum_squares = 0;

    double avg = mean(v);


    for(int i=0; i<v.size(); i++){

        sum_squares += (v[i] - avg)*(v[i] - avg);
    }

    return sum_squares/v.size();
}

double cv(vector<int> v){

    double avg = mean(v);
    double sd = stdev(v);

    return sd/avg;

}




vector<final_matrix> final_matrix_objects;


/* Driver function to test above functions */
int main()
{
  int n, r;

  n = 9;
  r = 3;

  // cin n later

  printCompositions(n, 0, r);

  ofstream myfile;

  myfile.open("comb.txt");

  for(int i=0; i< points_comb.size(); i++){

    for(vector<int>::iterator it = points_comb[i].begin(); it != points_comb[i].end(); ++it){

        myfile << *it << " ";
    }

    myfile<<endl;
  }
    myfile.close();

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

  /*

  for(int i=0; i< vec1.size(); i++){

    for(list<int>::iterator it = vec1[i].begin(); it != vec1[i].end(); ++it){

        cout<< *it <<" ";
    }

    cout<< endl;
  }

  cout<< "vec1 ends \n"; */

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

            vector<int> vec_copy_1;

      for(int p=0; p< vec2.size(); p++){

            list<int> lt_new = vec2[p];

            vec_copy_1.clear();

                // Iterate through the list and initial vector to remove common elements



            for(int j=0; j< vec_copy.size(); j++){

                bool present_not_1 = true;

                for(list<int>::iterator it = lt_new.begin(); it != lt_new.end(); ++it){

                    if( *it == vec_copy[j]){
                        present_not_1 = false;
                    }
                }

                if(present_not_1){
                    vec_copy_1.push_back(vec_copy[j]);
                }
            }

                list<int> l;


                vec3.clear();

                subset_new_1( vec_copy_1, 2, 2, 0, l);

                for(int z=0; z<vec3.size(); z++){


                        cluster_points_vector.clear();

                        cluster_points_vector.push_back(vec1[i]);

                        cluster_points_vector.push_back(vec2[p]);

                        cluster_points_vector.push_back(vec3[z]);

                        cluster_points.push_back(cluster_points_vector);


                }

      }

  }



  ofstream myfile2;

  myfile2.open("clusters.txt");


  // Print clusters vector

  cout<<"Cluster points siez is: "<<cluster_points.size()<<endl;


  for(int i=0; i<cluster_points.size(); i++){

    for(int j=0; j< cluster_points[i].size(); j++){

        list<int> lt = cluster_points[i][j];

        for(list<int>::iterator iter = lt.begin(); iter != lt.end(); ++iter){


        }

    }

     final_iteration element;

        element.vector_list = cluster_points[i];
        element.combination = points_comb[1];

        vector_final_iters.push_back(element);
  }


  // Output the object vector

  cout<<"Vector size is: "<< vector_final_iters.size()<<endl;



  cout<<" Reading from the object vector: \n\n";



  // Random scores

  int p[] = {50, 60, 70, 40, 56, 70, 56, 49, 70};

  // Random distances

  int dist[9][9];

  for(int i=0; i<9; i++){

    for(int j=0; j<9; j++){

        if(i==j){
            dist[i][j] = 0;
        }
        else{
            dist[i][j] = rand() % 10 + 1;
        }
    }
  }



  /* 3 conditions

  1) Scores should be optimum
  2) Distances should be minimum
  3) After selecting the points, select the nodes
  */

  // Population condition
  // The defined class is final_matrix

  // Pushing it to the final matrix vector

    for(int i=0; i<vector_final_iters.size(); i++){


        vector< list<int> > vector_ = vector_final_iters[i].vector_list;
        vector<int> comb_ = vector_final_iters[i].combination;

        final_matrix obj;

        obj.combination = comb_;
        obj.vector_list = vector_;




        for(int j=0; j<vector_.size(); j++){

                int population = 0;
                int distance = 0;

            for(list<int>::iterator it = vector_[j].begin(); it != vector_[j].end(); ++it){

                // Adding up the the populations in the respective clusters

                population += p[*it - 1];

                list<int>::iterator it2 = it;

                advance(it2, 1);


                for( it2 ; it2 != vector_[j].end(); it2++){

                    distance += dist[*it -1][*it2 - 1];

                  //  cout<<"distance is: " << distance<<endl<<endl;
                }

            }


            obj.population.push_back(population);
            obj.distances.push_back(distance);

            // Construct CV and distance norm

        }

        obj.dist_norm = DistanceNorm(obj.distances);
        obj.score_cv = cv(obj.population);
        obj.sum_cv_norm = obj.dist_norm + obj.score_cv;

        final_matrix_objects.push_back(obj);


  }

  // Displaying the final matrix vector

  // Also find out the lowest sum cluster

  int sum_min_index = -50;
  double sum_cv_min = 10000000;

    for(int i=0; i<final_matrix_objects.size(); i++){


        vector< list<int> > vector_ = final_matrix_objects[i].vector_list;
        vector<int> comb_ = final_matrix_objects[i].combination;
        vector<int> pop = final_matrix_objects[i].population;
        vector<int> distance = final_matrix_objects[i].distances;

        print_vec(comb_);

        cout<< "     ";

        for(int j=0; j<vector_.size(); j++){

            for(list<int>::iterator it = vector_[j].begin(); it != vector_[j].end(); ++it){

                cout<< *it <<" ";
            }
            cout<<"  ";
        }

        cout<< "      ";

        for(int j=0; j<pop.size(); j++){

            cout<< pop[j] <<" ";

        }

        cout<< "      ";

        for(int j=0; j<distance.size(); j++){

            cout<< distance[j] <<" ";

        }

        cout<< "      ";

        cout<< final_matrix_objects[i].dist_norm;


        cout<< "      ";

        cout<< final_matrix_objects[i].score_cv;

        cout<< "      ";

        cout<< final_matrix_objects[i].sum_cv_norm;

        if(final_matrix_objects[i].sum_cv_norm < sum_cv_min ){
            sum_cv_min = final_matrix_objects[i].sum_cv_norm ;
            sum_min_index = i ;
        }

        cout<<endl;
  }

  cout<< "\n\nThe min sum is: "<< sum_cv_min <<endl;

  cout<<" And the index is: "<< sum_min_index <<endl;

  // We got the min sum. let's display it

  cout<<"\n\nThe min cluster is: \n\n";

        vector< list<int> > vector_ = final_matrix_objects[sum_min_index].vector_list;
        vector<int> comb_ = final_matrix_objects[sum_min_index].combination;
        vector<int> pop = final_matrix_objects[sum_min_index].population;
        vector<int> distance = final_matrix_objects[sum_min_index].distances;

        print_vec(comb_);

        cout<< "     ";

        for(int j=0; j<vector_.size(); j++){

            for(list<int>::iterator it = vector_[j].begin(); it != vector_[j].end(); ++it){

                cout<< *it <<" ";
            }
            cout<<"  ";
        }

        // Find out the cluster center, ask Rahi.


  return 0;
}
