#ifndef NODE_H
#define NODE_H

#include <vector>

//node class declaration
class node {

	public:
		int depth;
		//cost f(n)
		int fn;
		int hn;
		vector <vector <int> > curr_state;
		
		node& operator=( const node& rhs ){
			this->depth = rhs.depth;
			this->fn = rhs.fn;
			this->hn = rhs.hn;
			this->curr_state = rhs.curr_state;
			
			return *this;
		}
		
		node(){
			depth = 0;
			fn = 0;
			hn = 0;
			curr_state = { {0,0,0}, {0,0,0}, {0,0,0} };
		}

};

//for caomparing the queue
struct CompareQueue{
		bool operator()(const node& lhs, const node& rhs) const{
			return lhs.fn > rhs.fn;
		}	
};

void z_index(int & zR, int & zC, vector <vector <int> > current){
    //finding 0 index
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(current.at(i).at(j) == 0){
                zR = i;
                zC = j;
            }
        }
    }    
}

//movement functions, returning integer if move legal
int m_left (vector <vector <int> > & current){
    
    int z_row = 0;
    int z_col = 0;
    
    z_index(z_row, z_col, current);
    
	//checking if move legal
	if(z_col == 0){
	       return 0;
	}
	//else perform move
	int temp;
	temp = current.at(z_row).at(z_col);
	current.at(z_row).at(z_col) = current.at(z_row).at(z_col - 1);
	current.at(z_row).at(z_col - 1) = temp;
	
	return 1;
}

int m_right (vector <vector <int> > & current){
    
    int z_row = 0;
    int z_col = 0;
    
    z_index(z_row, z_col, current);  
    
	//checking if move legal
	if(z_col == 2){
	       return 0;
	}
	
	//else perform move
	int temp;
	temp = current.at(z_row).at(z_col);
	current.at(z_row).at(z_col) = current.at(z_row).at(z_col + 1);
	current.at(z_row).at(z_col + 1) = temp;	
	
	return 1;
}

int m_down (vector <vector <int> > & current){
    
    int z_row = 0;
    int z_col = 0;
    
    z_index(z_row, z_col, current);
    
	//checking if move legal
	if(z_row == 2){
	       return 0;
	}
	
	//else perform move
	int temp;
	temp = current.at(z_row).at(z_col);
	current.at(z_row).at(z_col) = current.at(z_row + 1).at(z_col);
	current.at(z_row + 1).at(z_col) = temp;	
	
	return 1;	
}

int m_up (vector <vector <int> > & current){
    
    int z_row = 0;
    int z_col = 0;
    
    z_index(z_row, z_col, current);
    
	//checking if move legal
	if(z_row == 0){
	       return 0;
	}
	
	//else perform move
	int temp;
	temp = current.at(z_row).at(z_col);
	current.at(z_row).at(z_col) = current.at(z_row - 1).at(z_col);
	current.at(z_row - 1).at(z_col) = temp;		
	
	return 1;	
}

#endif
