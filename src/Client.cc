#include <stdio.h>
#include "ClientException.h"
#include <iostream>
#include "RamCloud.h"

using namespace std;

int main(int argc, char *argv[]){

try{
    if(argc!=2){
        fprintf(stderr,"Usage:% coordinatorLocator",argv[0])
    }
    RAMCloud::RamCloud cluster(argv[1]),"__unnamed__");
    cluster.openwhiskcall();
}
catch(RAMCloud::ClientException& e){
    fprintf(stderr,"Ramcloud exception:% s\n",e.str().c_str());
    return 1;
}
catch(RAMCloud::Exception e){
    fprintf(stderr,"Ramcloud exception: %\n",e.str().c_str());
    return 1;
}
}