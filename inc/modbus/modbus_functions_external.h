
extern unsigned short CRC16 (unsigned char *puchMsg, unsigned short usDataLen);

extern long GetTotMeas(void *pvMeasAddr);

extern _Bool check_addr_dig_oscilograph(unsigned short, unsigned short);
extern _Bool check_addr_measurements1(unsigned short, unsigned short);
extern _Bool check_addr_measurements2(unsigned short, unsigned short);
extern _Bool check_addr_measurements3(unsigned short, unsigned short);
extern _Bool check_addr_of_outputs(unsigned short, unsigned short);
extern _Bool check_addr_angles(unsigned short, unsigned short);
extern _Bool check_addr_sectors(unsigned short, unsigned short);
extern _Bool check_addr_floating_measurements(unsigned short, unsigned short);
extern _Bool check_addr_settings(unsigned short, unsigned short);
extern _Bool check_addr_activ_deactiv_ust(unsigned short);
extern _Bool check_addr_yust(unsigned short, unsigned short);
extern void start_response(unsigned char*, unsigned int);
extern void start_interprocessor_communications(unsigned short);

extern _Bool check_addr_dig_outputs(unsigned short, unsigned short);
extern _Bool check_addr_dig_inputs(unsigned short, unsigned short);
extern _Bool check_addr_active_func(unsigned short, unsigned short);
extern _Bool check_addr_tripped_func(unsigned short, unsigned short);
extern _Bool check_addr_global(unsigned short, unsigned short);
extern _Bool check_addr_ranking_DO1(unsigned short, unsigned short);   
extern _Bool check_addr_ranking_DI1(unsigned short, unsigned short);

extern void func1();
extern void func3();
extern void func5();
extern void func6();
extern void func15();
extern void func16();

