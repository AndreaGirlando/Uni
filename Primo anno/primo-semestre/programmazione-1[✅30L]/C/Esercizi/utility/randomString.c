unsigned int get_random() {
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

char* genString(int numeroCaratteri){

    char* string = malloc(numeroCaratteri * sizeof(char));

    for(int i = 0;i<numeroCaratteri;i++){
        string[i] = get_random() % (122 - 97 + 1) + 97;
    }
    string[numeroCaratteri] = '\0';

    return string;
}