#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_

namespace sdds {
    class PosApp{
        char m_fileName[255+1];
        int m_addstock;
        bool m_loaded;
        
    public:
        int menu();
        void addItem();
        void removeItem();
        void stockItem();
        void listItems();
        void POS();
        void saveRecs();
        void loadRecs();
        PosApp();
        PosApp(const char* fileName);
        ~PosApp();
        void run();
    };
}

#endif
