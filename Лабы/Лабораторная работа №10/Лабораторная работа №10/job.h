#ifndef JOB_H
#define JOB_H

// ��������� JobRequest ������������ ���������� � �������
struct JobRequest {
    char category; // ��������� ���������� ('M', 'S', 'W')
    int id; // ID-����� �������
    int time; // ����� ���������� ������� � �����

    // �������� < ��� ��������� �������
    bool operator<(const JobRequest& other) const {
        // ��������� ������� ������������ �� �������� ����������
        return time > other.time;
    }
};

#endif  // JOB_H