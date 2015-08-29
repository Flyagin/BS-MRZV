
unsigned short CRC16 (unsigned char *puchMsg, unsigned short usDataLen);

_Bool check_addr_global(unsigned short, unsigned short);
_Bool check_addr_ranking_DO1(unsigned short, unsigned short);
_Bool check_addr_ranking_DI1(unsigned short, unsigned short);
_Bool check_addr_dig_outputs(unsigned short, unsigned short);
_Bool check_addr_dig_inputs(unsigned short, unsigned short);
_Bool check_addr_active_func(unsigned short, unsigned short);
_Bool check_addr_tripped_func(unsigned short, unsigned short);

_Bool check_addr_dig_oscilograph(unsigned short, unsigned short);
_Bool check_addr_measurements1(unsigned short, unsigned short);
_Bool check_addr_measurements2(unsigned short, unsigned short);
_Bool check_addr_measurements3(unsigned short, unsigned short);
_Bool check_addr_of_outputs(unsigned short, unsigned short);
_Bool check_addr_angles(unsigned short, unsigned short);
_Bool check_addr_sectors(unsigned short, unsigned short);
_Bool check_addr_floating_measurements(unsigned short, unsigned short);
_Bool check_addr_settings(unsigned short, unsigned short);
_Bool check_addr_activ_deactiv_ust(unsigned short);
_Bool check_addr_yust(unsigned short, unsigned short);
void start_response(unsigned char*, unsigned int);
void start_interprocessor_communications(unsigned short);

void func1();
void func3();
void func5();
void func6();
void func15();
void func16();

