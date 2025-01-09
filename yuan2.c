#include <pbc.h>
#include <pbc_time.h>

int main(void) {
	pairing_t pairing;
	element_t P, PK, Yi, diP, hiPK, YihiPK, Vi, Ti, ki1Vi, ki1ViYi, hi1PK, T1, T1li1, tauiP, T2, ki2Vi, ki2ViYi, hi2PK, T3, T3li2, ci, sumP, A1;//GȺ
	element_t x, yi, hi, hix, di, vi, ti, ki, li, kivi, kividi, kividili, taui, hi1, ki1, li1, hi2, ki2, li2, tauI, sum;//������
	double time1, time2, time3, time4, time5, time6, chu, chu2, chu4, chu6, chu8, chu10, chu12;
	double Time1 = 0, Time2 = 0, Time3 = 0, Time4 = 0, Time5 = 0, Time6 = 0, Time7 = 0;




	a_param_input(pairing); // �Զ���������A��ԵĲ���
	element_init_Zr(x, pairing);
	element_init_Zr(yi, pairing);
	element_init_Zr(hi, pairing);
	element_init_Zr(hix, pairing);
	element_init_Zr(di, pairing);
	element_init_Zr(vi, pairing);
	element_init_Zr(ti, pairing);
	element_init_Zr(ki, pairing);
	element_init_Zr(li, pairing);
	element_init_Zr(kivi, pairing);
	element_init_Zr(kividi, pairing);
	element_init_Zr(kividili, pairing);
	element_init_Zr(taui, pairing);
	element_init_Zr(hi1, pairing);
	element_init_Zr(ki1, pairing);
	element_init_Zr(li1, pairing);
	element_init_Zr(hi2, pairing);
	element_init_Zr(ki2, pairing);
	element_init_Zr(li2, pairing);
	element_init_Zr(tauI, pairing);
	element_init_Zr(sum, pairing);


	element_init_G1(PK, pairing);
	element_init_G1(P, pairing);
	element_init_G1(Yi, pairing);
	element_init_G1(hiPK, pairing);
	element_init_G1(YihiPK, pairing);
	element_init_G1(diP, pairing);
	element_init_G1(Vi, pairing);
	element_init_G1(Ti, pairing);
	element_init_G1(ki1Vi, pairing);
	element_init_G1(ki1ViYi, pairing);
	element_init_G1(T1, pairing);
	element_init_G1(T1li1, pairing);
	element_init_G1(tauiP, pairing);
	element_init_G1(T2, pairing);
	element_init_G1(hi1PK, pairing);
	element_init_G1(ki2ViYi, pairing);
	element_init_G1(hi2PK, pairing);
	element_init_G1(T3, pairing);
	element_init_G1(T3li2, pairing);
	element_init_G1(ci, pairing);
	element_init_G1(sumP, pairing);
	element_init_G1(A1, pairing);
	element_init_G1(ki2Vi, pairing);

	time3 = get_time();
	for (int i = 0; i < 100; i++) {           //ѭ��һ�ζ�Ӧһ��������
		if (!pairing_is_symmetric(pairing)) {
			fprintf(stderr, "�������ڶԳ����\n");
			exit(1);
		}
		time5 = get_time();

		printf("ϵͳ��ʼ��\n");
		// ϵͳ��ʼ���׶�
		printf("ϵͳ��ʼ��\n");
		time1 = get_time();
		element_random(x); // ����KGC���������Կ
		element_random(P); // ����G������ԪP
		element_mul_zn(PK, P, x);
		time2 = get_time();
		element_printf("P = %B\n", P);
		element_printf("x = %B\n", x);
		element_printf("PK = %B\n", PK);
		printf("ϵͳ��ʼ������ʱ�� = %fs\n", time2 - time1);
		Time1 = Time1 + (time2 - time1);
		printf("ϵͳ��ʼ��������ʱ�� = %fs\n", Time1);
		chu = Time1 / (i + 1);
		printf("��%d��ϵͳ��ʼ������ƽ��ʱ��Ϊ%fs\n", i + 1, chu);


		//��ȡ������Կ 
		printf("��ȡ������Կ\n");
		time1 = get_time();
		element_random(yi);
		element_mul_zn(Yi, P, yi);
		element_random(hi);
		element_add(di, yi, hix);//di=yi+hix
		element_mul_zn(diP, P, di);
		element_mul_zn(hix, hi, x);
		element_mul_zn(hiPK, PK, hi);
		element_add(YihiPK, Yi, hiPK);
		time2 = get_time();
		if (!element_cmp(diP, YihiPK))
		{
			element_printf("diP=Yi+hiPK");
			printf("Di����Ч�ģ�\n");
		}
		else
		{
			printf("Di����Ч�ģ�\n");
		}
		element_printf("yi=%B\n", yi);
		element_printf("Yi=%B\n", Yi);
		element_printf("hi=%B\n", hi);
		element_printf("hix=%B\n", hix);
		element_printf("di=%B\n", di);
		element_printf("diP=%B\n", diP);
		element_printf("hiPK=%B\n", hiPK);
		element_printf("YihiPK=%B\n", YihiPK);
		printf("��ȡ������Կʱ�� = %fs\n", time2 - time1);
		Time2 = Time2 + (time2 - time1);
		printf("��ȡ������Կ��ʱ�� = %fs\n", Time2);
		chu2 = Time2 / i + 1;
		printf("��%d����ȡ������Կ����ƽ��ʱ��Ϊ%fs\n", i + 1, chu2);

		//�����û���Կ
		printf("�����û���Կ\n");
		time1 = get_time();
		element_random(vi);
		element_mul_zn(Vi, P, vi);
		time2 = get_time();
		element_printf("vi=%B\n", vi);
		element_printf("Vi=%B\n", Vi);
		printf("������Կʱ�� = %fs\n", time2 - time1);
		Time3 = Time3 + (time2 - time1);
		printf("������Կ��ʱ�� = %fs\n", Time3);
		chu4 = Time3 / i + 1;
		printf("��%d�������û���Կ����ƽ��ʱ��Ϊ%fs\n", i + 1, chu4);

		//ǩ��
		printf("ǩ��\n");
		time1 = get_time();
		element_random(ti);
		element_mul_zn(Ti, P, ti);
		element_random(ki);
		element_random(li);
		element_mul_zn(kivi, ki, vi);
		element_add(kividi, kivi, di);
		element_mul_zn(kividili, li, kividi);
		element_add(taui, ti, kividili);
		time2 = get_time();
		element_printf("ti=%B\n", ti);
		element_printf("Ti=%B\n", Ti);
		element_printf("ki=%B\n", ki);
		element_printf("li=%B\n", li);
		element_printf("kivi=%B\n", kivi);
		element_printf("kividi=%B\n", kividi);
		element_printf("kividili=%B\n", kividili);
		element_printf("taui=%B\n", taui);
		printf("ǩ��ʱ�� = %fs\n", time2 - time1);
		Time4 = Time4 + time2 - time1;
		printf("ǩ����ʱ�� = %fs\n", Time4);
		chu6 = Time4 / i + 1;
		printf("��%d��ǩ������ƽ��ʱ��Ϊ%fs\n", i + 1, chu6);

		//��֤
		printf("��֤\n");
		time1 = get_time();
		//Ҫ��ָ������еĹ�ϣ����ĳֵ�����ǽ��ܼ���ĳֵ��ֱ����set��������
		element_set(hi1, hi);
		element_set(ki1, ki);
		element_set(li1, li);
		element_mul_zn(ki1Vi, Vi, ki1);   //ki1��������Vi G1Ⱥ
		element_mul_zn(hi1PK, PK, hi1);   //hi������,PK G1Ⱥ
		element_add(ki1ViYi, ki1Vi, Yi);   //ֻ��������ӡ�G1Ⱥ���
		element_add(T1, ki1ViYi, hi1PK);
		element_mul_zn(T1li1, T1, li1);
		element_mul_zn(tauiP, P, taui);
		element_add(T2, Ti, T1li1);
		time2 = get_time();
		if (!element_cmp(tauiP, T2))   //cmp �ж�ʽ���Ƿ����
		{
			element_printf("tauiP=Ti+li1(ki1Vi+Yi+hi1PK)");
			printf("ǩ����Ч��\n");
		}
		else
		{
			printf("ǩ����Ч��\n");

		}
		element_printf("hi1=%B\n", hi1);
		element_printf("ki1=%B\n", ki1);
		element_printf("li1=%B\n", li1);
		element_printf("ki1Vi=%B\n", ki1Vi);
		element_printf("hi1PK=%B\n", hi1PK);
		element_printf("ki1ViYi=%B\n", ki1ViYi);
		element_printf("T1=%B\n", T1);
		element_printf("T1li1=%B\n", T1li1);
		element_printf("tauiP=%B\n", tauiP);
		element_printf("T2=%B\n", T2);
		printf("��֤����ʱ�� = %fs\n", time2 - time1);
		Time5 = Time5 + time2 - time1;
		printf("��֤������ʱ�� = %fs\n", Time5);
		chu8 = Time5 / i + 1;
		printf("��%d����֤����ƽ��ʱ��Ϊ%fs\n", i + 1, chu8);  //�䲻�������ν��ʱ��Ҫ��


		//�ۺ�ǩ��
		printf("�ۺ�ǩ��\n");
		time1 = get_time();   //��ʼʱ��
		element_set(tauI, taui);
		element_add(sum, sum, tauI);
		element_printf("tau=%d\n", sum);
		time2 = get_time();   //����ʱ��
		printf("�ۺ�ǩ������ʱ�� =%fs\n", time2 - time1);
		Time6 = Time6 + time2 - time1;
		printf("�ۺ�ǩ��������ʱ�� =%fs\n", Time6);
		chu10 = Time6 / i + 1;   //ƽ��ʱ��
		printf("��%d�ξۺ�ǩ������ƽ��ʱ��Ϊ%fs\n", i + 1, chu10);

		//�ۺ�ǩ����֤
		printf("�ۺ�ǩ����֤\n");
		time1 = get_time();
		element_set(hi2, hi);
		element_set(ki2, ki);
		element_set(li2, li);
		element_mul_zn(ki2Vi, Vi, ki2);
		element_add(ki2ViYi, ki2Vi, Yi);//kiVi+Yi
		element_mul_zn(hi2PK, PK, hi2);
		element_add(T3, ki2ViYi, hi2PK);//kiVi+Yi+hiPK
		element_mul_zn(T3li2, T3, li2);//li(kiVi+Yi+hiPK)
		element_add(ci, Ti, T3li2);
		element_add(A1, A1, ci);
		if (!element_cmp(sumP, A1))
		{
			element_printf("tauP=A1�ۼ�ֵ)");
			printf("�ۺ�ǩ����Ч��\n");
		}
		else
		{
			printf("�ۺ�ǩ����Ч��\n");
		}
		time2 = get_time();
		printf("�ۺ�ǩ����֤����ʱ�� =%fs\n", time2 - time1);
		Time7 = Time7 + time2 - time1;
		printf("�ۺ�ǩ����֤������ʱ�� =%fs\n", Time7);
		chu12 = Time7 / i + 1;
		printf("��%d�ξۺ�ǩ����֤����ƽ��ʱ��Ϊ%fs\n", i + 1, chu12);

		time6 = get_time();
		printf("��%d��ѭ������ʱ��Ϊ%fs\n", i + 1, time6 - time5);
	}
	time4 = get_time();
	printf("ȫ��ѭ����������ʱ�� =%fs\n", time4 - time3);
	printf("ȫ��ѭ����������ʱ�� =%fs\n", Time1 + Time2 + Time3 + Time4 + Time5 + Time6 + Time7);


	printf("ϵͳ��ʼ������ƽ��ʱ�� = % fs\n", chu);
	printf("��ȡ������Կ����ƽ��ʱ�� = % fs\n", chu2);
	printf("�����û���Կ����ƽ��ʱ�� = % fs\n", chu4);
	printf("ǩ������ƽ��ʱ�� = % fs\n", chu6);
	printf("��֤����ƽ��ʱ�� = % fs\n", chu8);
	printf("�ۺ�ǩ������ƽ��ʱ�� = % fs\n", chu10);
	printf("�ۺ�ǩ����֤����ƽ��ʱ�� = % fs\n", chu12);
}