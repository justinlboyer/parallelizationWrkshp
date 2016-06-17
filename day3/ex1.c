
#include <stdio.h>
#include "mpi.h"

int main(int argc, char** argv){

  int my_PE_num, data=42, datatoreceive, index;
  MPI_Status status;
  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &my_PE_num);

  for(index=0; index<8; index++){
	if(my_PE_num == index){
	MPI_Send(&data, 1, MPI_INT, index+1%8, 10, MPI_COMM_WORLD);
	}
	else{
	MPI_Recv(&datatoreceive, 1, MPI_INT, index, 10, MPI_COMM_WORLD, &status);
	printf("%d recieved data\n", index+1);
	}
}

  MPI_Finalize();

}
