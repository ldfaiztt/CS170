/*
 * ProcessManager header
 *
 * This class keeps track of the current PCBs and manages their creation and
 * deletion.
*/

#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#define MAX_PROCESSES 32

#include "pcb.h"
#include "synch.h"

class AddrSpace;

class ProcessManager {

    public:
        ProcessManager();
        ~ProcessManager();
        int getPID();  // allocates free PID to a new addrspace
        int getStatus(int pid);  // allows processes to wait on others
        void clearPID(int);      // frees the specified PID
        void addProcess(PCB* pcb, int pid); 
        void broadcast(int pid);
        void join(int pid);


    private:
        BitMap processesBitMap;
        PCB** pcbList;             // PID is array index
        Condition** conditionList; // allows controlling join/exit
        Lock** lockList;           // also for join/exit
        AddrSpace** addrSpaceList;
        int pcbStatuses[MAX_PROCESSES];
        int processesWaitingOnPID[MAX_PROCESSES];
        int numAvailPIDs;
};

#endif // PROCESS_MANAGER_H
