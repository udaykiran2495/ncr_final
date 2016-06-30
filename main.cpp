#include<stdio.h>
#include <vector>
#include <iostream>
#include <list>
#include <fstream>
#include "Solution.h"   // Solution class, needed for combinations
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iterator>     // std::advance
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

vector< vector<int> > points_comb;

template<class T>
class BinarySearchTree
{
public:
	struct tree_node
	{
		tree_node* left_child;
		tree_node* right_sibling;
		tree_node* parent;
		T data;
		T removed_elements; // elements removed until that point
	};
	tree_node* root;

	BinarySearchTree()
	{
		root = NULL;
	}

	tree_node* curr_depth; // This tells about the level of the tree, in which to add the subsets
	tree_node* curr_depth_iter; // This parses along right
    tree_node* parent_above_level; // parent of the above level, initialize it to root now
    tree_node* curr_iter_child; //Going down in a level.
    tree_node* curr_node;
    vector<tree_node*> leaf_nodes;

	bool isEmpty() const { return root==NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	void leafNodes(tree_node*);
	void insertRoot(T);
	void empty_left(tree_node*, vector<int> &);
	void insert(T);
	void remove(T);
	bool search(T);
};

// Declaring global tree, as we need only 1
    BinarySearchTree< vector<int> > b;



template <class T>
void BinarySearchTree<T>::insertRoot(T d)
{
	tree_node* t = new tree_node;

	t->data = d;
	t->left_child = NULL;
	t->right_sibling = NULL;
	t->parent = NULL;
	// is this a new tree?
	if(isEmpty()) root = t;

}


template <class T>
void BinarySearchTree<T>::insert(T d)
{
	tree_node* t = new tree_node;
	tree_node* parent;


	t->data = d;
	t->left_child = NULL;
	t->right_sibling = NULL;
	t->parent = b.curr_depth;
	parent = NULL;



	// is this a new tree?
	if(isEmpty()) root = t;
	else
	{
		//Note: ALL insertions are as leaf nodes
		tree_node* curr;

        t->parent = curr_depth;





		if(curr_depth->left_child == NULL){

            curr_depth->left_child = t;

		}
		else{

            curr = curr_depth->left_child;



            while(curr)
            {
			parent = curr;
			curr = curr->right_sibling;
            }

            parent->right_sibling = t;

		}

		// Find the Node's parent


	}
}


  ofstream myfile;

 void print_vec(vector<int> v){



             myfile<<"vector is: ";

     for(int i=0; i< v.size(); i++){

        cout<< v[i]<<" ";

        myfile << v[i]<< " ";
     }

    cout<<endl;
     myfile<<endl;



 }




template <class T>
void BinarySearchTree<T>::print_preorder()
{
    preorder(root);
}

template <class T>
void BinarySearchTree<T>::preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<"vector is:"<<endl;
        print_vec(p->data);
        if(p->left_child) preorder(p->left_child);
        if(p->right_sibling) preorder(p->right_sibling);
    }
    else return;
}





// Subset function
void print( vector<int> &v){

  //  cout<<endl;

    b.insert(v);

}

void remove_common(vector<int> &arr, vector<int> parents){  // original array and parent

    vector<int> vec_copy;

    vec_copy.clear();

    for(int j=0; j< arr.size(); j++){

        bool present_not = true;

        for(vector<int>::iterator it = parents.begin(); it != parents.end(); ++it){

            if( *it == arr[j]){
                present_not = false;
            }
        }

        if(present_not){
            vec_copy.push_back(arr[j]);
        }
    }

    arr.clear();

    arr = vec_copy; // remove the elements and output the vector

}

void subset(vector<int> &arr, int size, int left, int index, vector<int> &v){
    if(left==0){
        print(v);
        return;
    }
    for(int i=index; i<size;i++){
        v.push_back(arr[i]);
        subset(arr, size, left-1, i+1, v);
        v.pop_back();

    }

}

template<class T>
void BinarySearchTree<T>::empty_left(tree_node* p, vector<int> &remove_elements)
{
    if(p != NULL)
    {

        if(p->left_child){
          remove_elements.insert(remove_elements.end(),p->data.begin(), p->data.end());

         // print_vec(remove_elements);
          preorder(p->left_child);
        }

    }
    else return;
}


// main subset function
template <class T>
void BinarySearchTree<T>::leafNodes(tree_node* t)
{
      if(t == NULL)
        return;
       if(t->left_child == NULL && t->right_sibling ==NULL){
            b.leaf_nodes.push_back(t);
       }
       leafNodes(t->left_child);
       leafNodes(t->right_sibling);
}




void subset_comb(vector<int> &arr, int size, vector<int> &comb){

    b.insertRoot(arr);

    // Initailizing root


    vector<int> v;

    vector<int> arr_copy;

    vector<int> remove_elements;

    /*      <1,2,3,4,5,6,7,8,9>
            /
            <1>-><2>-><3>-><4>-><5>-><6>-><7>-><8>-><9>
            /
           <2,3>-><3,4>
    */


    for(vector<int>::iterator iter = comb.begin(); iter != comb.end(); ++iter){

        b.leaf_nodes.clear(); // clear the leaf_nodes vector

        b.leafNodes(b.root);  // add all the leaf nodes to leaf_nodes vector

        //leaf_nodes vector is obtained

        vector<BinarySearchTree< vector<int> >::tree_node*> vec = b.leaf_nodes;


        for(vector<BinarySearchTree< vector<int> >::tree_node*>::iterator iter2 = vec.begin(); iter2 != vec.end(); ++iter2){

            b.curr_depth = *iter2;

            arr_copy = arr;

            // add all the parent elements to the remove_elements vector

            BinarySearchTree< vector<int> >::tree_node* parent_elem;

            parent_elem = b.curr_depth;

            remove_elements.clear();

            /*


            while(1){


               // cout<<"check"<<endl;

                if(parent_elem->parent){

                    parent_elem = parent_elem->parent;

                  //  cout<<"parent vector is: "<<endl;

                    //print_vec(parent_elem->data);
                }else{
                     break;
                }


                remove_elements.insert(remove_elements.end(), parent_elem->data.begin(), parent_elem->data.end());



            } */

            remove_common(arr_copy, remove_elements);

            subset(arr_copy, arr_copy.size(), *iter, 0, v);
        }


    }



}



// Subset function
// Global variable to add lists


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
    vector<int> node_center;
    double score_cv;
    double score_cv_norm;
    double distances_sum;
    double distances_sum_norm; // norm here means normalized, i.e divide it by the largest of all the populations
    double distances_diff_sum;
    double distances_diff_sum_norm;
    double norm; // the cartesian distance of the 3 parameters

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

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}


/* Driver function */
int main()
{
  int n, r;

  // Input from file


  ifstream inputfile;

  inputfile.open("input.csv");

  string line;

  getline (inputfile,line , ',');
  getline (inputfile,line ,',');
  stringstream ss(line);
  ss >> n;


  getline (inputfile,line);
  getline (inputfile,line, ',');
  getline (inputfile,line, ',');

  stringstream ss2(line);

  ss2>>r;

  cout<<"n is: "<<n<<endl;
  cout<<"r is: "<<r<<endl;

  cout<<"Please update the input.xlsx file in the folder and convert it into CSV file of same name before you run the program"<<endl;

  // scores

      double score;

      vector<double> p;  // score/value population vector
      vector<string> place_names;
      string place;



    getline (inputfile,line);

    for(int i=0; i<n; i++){

        getline (inputfile,line);

        getline (inputfile,line, ',');

        stringstream ss5(line);

        ss5>> place;

        place_names.push_back(place);

        getline (inputfile,line, ',');

        stringstream ss4(line);

        ss4>>score;
        p.push_back(score);
    }


    double dist[n][n]; // distances vector. This is based on the indexes of the places

    double distance;
    string line_var;
    char ch;

    inputfile.clear();

    inputfile.seekg(0, ios::beg);

    getline (inputfile,line_var);
    getline (inputfile,line_var);
    getline (inputfile,line_var);

    vector<double> dist_vec;

    while(1)
    {
        getline (inputfile,line_var);

        if(inputfile.eof()) break;


       vector<string> tokens = split(line_var, ',');

       vector<string>::iterator it = tokens.end();

       it = it - 1;

       string s = *it;

       double num = atof( s.c_str());
       dist_vec.push_back(num);

    }


    int dist_index = 0;


      for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            if(i==j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = dist_vec[dist_index];
                dist_index++;
            }
        }
      }

    inputfile.close();

 /*
 Now we have all the inputs
 total points n, clusters r
 population/score/value vector p
 distance between all points matrix dist, which is 2 d array

 */





    ofstream myfile;
// Combinations code

    myfile.open("comb.txt");

	const int S_LIMIT = n;

	int vals[n];

	for(int i=0; i<n; i++){

        vals[i] = i+1;

	}
	Solution so;

	int S = 15;


    cout << "For n = " << S << ":" << endl;

	vector<vector<int>>	result = so.getComb(vals, sizeof(vals)/sizeof(int), S);

    points_comb = result;

    for(int i=0; i<points_comb.size(); i++){

        for(int j=0; j<points_comb[i].size(); j++){
            cout<<points_comb[i][j]<<" ";
        }
        cout<<endl;
    }


  // We get point_comb vector complete.

  // Combinations are done

  // Now let's distribute the points

  	vector<int> points;

	for(int i=0; i<n; i++){
        points.push_back(i+1);
	}

	// Main function that would distribute the values

	vector<int> vec = points_comb[2]; // random allocation for now

	  subset_comb(points, points.size(), vec );

/*


                        cluster_points_vector.clear();

                        cluster_points_vector.push_back(vec1[i]);

                        cluster_points_vector.push_back(vec2[p]);

                        cluster_points_vector.push_back(vec3[z]);

                        cluster_points.push_back(cluster_points_vector);

}
*/






  // Print clusters vector

  cout<<"Cluster points size is: " << cluster_points.size()<<endl;


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

                }

            }


            obj.population.push_back(population);
         //   obj.distances.push_back(distance);

            // Construct CV and distance norm

        }

       // obj.dist_norm = DistanceNorm(obj.distances);
        obj.score_cv = cv(obj.population);
//        obj.sum_cv_norm = obj.dist_norm + obj.score_cv;

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
  //      vector<int> distance = final_matrix_objects[i].distances;

       // print_vec(comb_);

       // cout<< "     ";

        for(int j=0; j<vector_.size(); j++){

            for(list<int>::iterator it = vector_[j].begin(); it != vector_[j].end(); ++it){

           //     cout<< *it <<" ";
            }
          //  cout<<"  ";
        }

      //  cout<< "      ";

        for(int j=0; j<pop.size(); j++){

        //    cout<< pop[j] <<" ";

        }

      //  cout<< "      ";

    //    for(int j=0; j<distance.size(); j++){

      //      cout<< distance[j] <<" ";

        }

      //  cout<< "      ";

       // cout<< final_matrix_objects[i].dist_norm;


       // cout<< "      ";

       // cout<< final_matrix_objects[i].score_cv;

      //  cout<< "      ";

     //   cout<< final_matrix_objects[i].sum_cv_norm;

      //  if(final_matrix_objects[i].sum_cv_norm < sum_cv_min ){
        //    sum_cv_min = final_matrix_objects[i].sum_cv_norm ;
          //  sum_min_index = i ;
       // }

     //   cout<<endl;
  //}



  // We got the min sum. let's display it

  // Find out the center nodes of the obtained clusters

    cout<<"\n\nThe min cluster is: \n\n";

    /*

    vector< list<int> > vector_ = final_matrix_objects[sum_min_index].vector_list;
    vector<int> comb_ = final_matrix_objects[sum_min_index].combination;
    vector<int> pop = final_matrix_objects[sum_min_index].population;
//    vector<int> distance = final_matrix_objects[sum_min_index].distances;

    print_vec(comb_);



    cout<< "     ";

    for(int j=0; j<vector_.size(); j++){


        for(list<int>::iterator it = vector_[j].begin(); it != vector_[j].end(); ++it){

            cout<< *it <<" ";

        }

        cout<<"  ";

    } */

  return 0;
}
