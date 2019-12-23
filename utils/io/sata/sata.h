typedef struct DEVICE{
    char* base;
    char* dev_ctl;
};

int REG_CYL_LO = 4;
int REG_CYL_HI = 5;
int REG_DEVSEL = 6;

int ATADEV_PATAPI = 0;
int ATADEV_SATAPI = 1;
int ATADEV_PATA = 2;
int ATADEV_SATA = 3;
int ATADEV_UNKNOWN = 4;