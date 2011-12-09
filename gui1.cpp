#include<windows.h>
#include<tlhelp32.h>
#include<stdio.h>
int main(){
    PROCESSENTRY32 pe32;
    pe32.dwSize=sizeof(pe32);
    HANDLE hPs=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    if(hPs==INVALID_HANDLE_VALUE)
    {
        printf("error\n");
        return -1;
    }
    BOOL bMore = ::Process32First(hPs,&pe32);
    while(bMore){
        printf("   %s\n",pe32.szExeFile);
        printf("   %u\n",pe32.th32ProcessID);
        bMore = :: Process32Next(hPs,&pe32);

    }
    ::CloseHandle(hPs);
}
