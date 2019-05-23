// Copyright (c) 2014-2019 Coin Sciences Ltd
// MultiChain code distributed under the GPLv3 license, see COPYING file.

#include "multichain/multichain.h"
#include "chainparams/globals.h"
#include "utils/util.h"

int main(int argc, char* argv[])
{
    int err;
    int version,v;
    char fileName[MC_DCT_DB_MAX_PATH];
    char DataDirArg[MC_DCT_DB_MAX_PATH];
    int isSetDataDirArg;
    FILE *fHan;
    
    mc_MultichainParams* params;
    mc_MultichainParams* paramsOld;
    mc_gState=new mc_State;
     
    mc_gState->m_Params->Parse_Util_Version(argc, argv, MC_ETP_UTIL);
    mc_CheckDataDirInConfFile();

    mc_gState->m_Params->ReadConfig(NULL);
    
    mc_ExpandDataDirParam();
    
    printf("\nMultiChain %s Utilities (latest protocol %d)\n\n",mc_BuildDescription(mc_gState->GetNumericVersion()).c_str(),mc_gState->GetProtocolVersion());
             
    err=MC_ERR_OPERATION_NOT_SUPPORTED;
    
    if(err == MC_ERR_OPERATION_NOT_SUPPORTED)
    {
        mc_GetFullFileName("<blockchain-name>","params", ".dat",MC_FOM_RELATIVE_TO_DATADIR,fileName);
        printf("You do not have permission to use this module:\n");
        /*printf("  multichain-util create <blockchain-name>  ( <protocol-version> = %d ) [options]        Creates new multichain configuration file %s with default parameters\n",
                mc_gState->GetProtocolVersion(),fileName);
        mc_GetFullFileName("<new-blockchain-name>","params", ".dat",MC_FOM_RELATIVE_TO_DATADIR,fileName);
        printf("  multichain-util clone <old-blockchain-name> <new-blockchain-name> [options]               Creates new multichain configuration file %s copying parameters\n",fileName);
        */ 
        /* isSetDataDirArg=mc_GetDataDirArg(DataDirArg);
        if(isSetDataDirArg)
        {
            mc_UnsetDataDirArg();
        }                
        mc_GetFullFileName("<old-blockchain-name>","params", ".dat",MC_FOM_RELATIVE_TO_DATADIR,fileName);
        if(isSetDataDirArg)
        {
            mc_SetDataDirArg(DataDirArg);
        }                
        printf("                                                                                            from %s\n",fileName);
        printf("\n");
        printf("Options:\n");
        printf("  -datadir=<dir>                              Specify data directory\n");
        printf("  -<parameter-name>=<parameter-value>         Specify blockchain parameter value, e.g. -anyone-can-connect=true\n\n");
        */
    }
            
    delete mc_gState;

    if(err)
    {
        return 1;
    }
    
    return 0;
}
