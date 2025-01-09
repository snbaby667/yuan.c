#include <pbc.h>
#include <pbc_time.h>

int main(void) {
	pairing_t pairing;
	element_t P, PK, Yi, diP, hiPK, YihiPK, Vi, Ti, ki1Vi, ki1ViYi, hi1PK, T1, T1li1, tauiP, T2, ki2Vi, ki2ViYi, hi2PK, T3, T3li2, ci, sumP, A1;//G群
	element_t x, yi, hi, hix, di, vi, ti, ki, li, kivi, kividi, kividili, taui, hi1, ki1, li1, hi2, ki2, li2, tauI, sum;//整数集
	double time1, time2, time3, time4, time5, time6, chu, chu2, chu4, chu6, chu8, chu10, chu12;
	double Time1 = 0, Time2 = 0, Time3 = 0, Time4 = 0, Time5 = 0, Time6 = 0, Time7 = 0;




	a_param_input(pairing); // 自动输入类型A配对的参数
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
	for (int i = 0; i < 100; i++) {           //循环一次对应一个传感器
		if (!pairing_is_symmetric(pairing)) {
			fprintf(stderr, "仅适用于对称配对\n");
			exit(1);
		}
		time5 = get_time();

		printf("系统初始化\n");
		// 系统初始化阶段
		printf("系统初始化\n");
		time1 = get_time();
		element_random(x); // 生成KGC的随机主密钥
		element_random(P); // 生成G的生成元P
		element_mul_zn(PK, P, x);
		time2 = get_time();
		element_printf("P = %B\n", P);
		element_printf("x = %B\n", x);
		element_printf("PK = %B\n", PK);
		printf("系统初始化所用时间 = %fs\n", time2 - time1);
		Time1 = Time1 + (time2 - time1);
		printf("系统初始化所用总时间 = %fs\n", Time1);
		chu = Time1 / (i + 1);
		printf("第%d次系统初始化所用平均时间为%fs\n", i + 1, chu);


		//提取部分密钥 
		printf("提取部分密钥\n");
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
			printf("Di是有效的！\n");
		}
		else
		{
			printf("Di是无效的！\n");
		}
		element_printf("yi=%B\n", yi);
		element_printf("Yi=%B\n", Yi);
		element_printf("hi=%B\n", hi);
		element_printf("hix=%B\n", hix);
		element_printf("di=%B\n", di);
		element_printf("diP=%B\n", diP);
		element_printf("hiPK=%B\n", hiPK);
		element_printf("YihiPK=%B\n", YihiPK);
		printf("提取部分密钥时间 = %fs\n", time2 - time1);
		Time2 = Time2 + (time2 - time1);
		printf("提取部分密钥总时间 = %fs\n", Time2);
		chu2 = Time2 / i + 1;
		printf("第%d次提取部分秘钥所用平均时间为%fs\n", i + 1, chu2);

		//设置用户密钥
		printf("设置用户密钥\n");
		time1 = get_time();
		element_random(vi);
		element_mul_zn(Vi, P, vi);
		time2 = get_time();
		element_printf("vi=%B\n", vi);
		element_printf("Vi=%B\n", Vi);
		printf("设置密钥时间 = %fs\n", time2 - time1);
		Time3 = Time3 + (time2 - time1);
		printf("设置密钥总时间 = %fs\n", Time3);
		chu4 = Time3 / i + 1;
		printf("第%d次设置用户秘钥所用平均时间为%fs\n", i + 1, chu4);

		//签名
		printf("签名\n");
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
		printf("签名时间 = %fs\n", time2 - time1);
		Time4 = Time4 + time2 - time1;
		printf("签名总时间 = %fs\n", Time4);
		chu6 = Time4 / i + 1;
		printf("第%d次签名所用平均时间为%fs\n", i + 1, chu6);

		//验证
		printf("验证\n");
		time1 = get_time();
		//要想恢复此题中的哈希函数某值或者是解密计算某值，直接用set函数即可
		element_set(hi1, hi);
		element_set(ki1, ki);
		element_set(li1, li);
		element_mul_zn(ki1Vi, Vi, ki1);   //ki1整数集，Vi G1群
		element_mul_zn(hi1PK, PK, hi1);   //hi整数集,PK G1群
		element_add(ki1ViYi, ki1Vi, Yi);   //只能两数相加。G1群相加
		element_add(T1, ki1ViYi, hi1PK);
		element_mul_zn(T1li1, T1, li1);
		element_mul_zn(tauiP, P, taui);
		element_add(T2, Ti, T1li1);
		time2 = get_time();
		if (!element_cmp(tauiP, T2))   //cmp 判断式子是否相等
		{
			element_printf("tauiP=Ti+li1(ki1Vi+Yi+hi1PK)");
			printf("签名有效！\n");
		}
		else
		{
			printf("签名无效！\n");

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
		printf("验证所用时间 = %fs\n", time2 - time1);
		Time5 = Time5 + time2 - time1;
		printf("验证所用总时间 = %fs\n", Time5);
		chu8 = Time5 / i + 1;
		printf("第%d次验证所用平均时间为%fs\n", i + 1, chu8);  //输不输出无所谓，时间要留


		//聚合签名
		printf("聚合签名\n");
		time1 = get_time();   //开始时间
		element_set(tauI, taui);
		element_add(sum, sum, tauI);
		element_printf("tau=%d\n", sum);
		time2 = get_time();   //结束时间
		printf("聚合签名所用时间 =%fs\n", time2 - time1);
		Time6 = Time6 + time2 - time1;
		printf("聚合签名所用总时间 =%fs\n", Time6);
		chu10 = Time6 / i + 1;   //平均时间
		printf("第%d次聚合签名所用平均时间为%fs\n", i + 1, chu10);

		//聚合签名验证
		printf("聚合签名验证\n");
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
			element_printf("tauP=A1累加值)");
			printf("聚合签名有效！\n");
		}
		else
		{
			printf("聚合签名无效！\n");
		}
		time2 = get_time();
		printf("聚合签名验证所用时间 =%fs\n", time2 - time1);
		Time7 = Time7 + time2 - time1;
		printf("聚合签名验证所用总时间 =%fs\n", Time7);
		chu12 = Time7 / i + 1;
		printf("第%d次聚合签名验证所用平均时间为%fs\n", i + 1, chu12);

		time6 = get_time();
		printf("第%d次循环所用时间为%fs\n", i + 1, time6 - time5);
	}
	time4 = get_time();
	printf("全部循环结束所用时间 =%fs\n", time4 - time3);
	printf("全部循环结束所用时间 =%fs\n", Time1 + Time2 + Time3 + Time4 + Time5 + Time6 + Time7);


	printf("系统初始化所用平均时间 = % fs\n", chu);
	printf("提取部分秘钥所用平均时间 = % fs\n", chu2);
	printf("设置用户秘钥所用平均时间 = % fs\n", chu4);
	printf("签名所用平均时间 = % fs\n", chu6);
	printf("验证所用平均时间 = % fs\n", chu8);
	printf("聚合签名所用平均时间 = % fs\n", chu10);
	printf("聚合签名验证所用平均时间 = % fs\n", chu12);
}