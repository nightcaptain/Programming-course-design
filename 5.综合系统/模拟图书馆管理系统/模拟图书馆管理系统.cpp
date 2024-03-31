#include<bits/stdc++.h>//万能头文件，减少代码量

using namespace std;

//将数据文本定义，方便调用
#define BF "book.txt"
#define UF "useraccount.txt"
#define AF "adminaccount.txt"

int user_cnt = 0;//用户计数器
int book_cnt = 0;//图书计数器
int admin_cnt = 1;//管理员计数器

typedef struct {
	int borrow_books_num = 0;
	char borrow_books[10][30];//最多借十本书，后为书的id
	char ID[30];//读者的编号,如00001
	char name[30];//读者的姓名
}USERS;

typedef struct {
	char ID[30];//管理员的ID
}ADMIN;

typedef struct {
	int whole_num;//馆藏数量
	int left_num;//剩余数量，未被借走
	char name[30];//图书名字
	char ID[30];//图书编号
	int record_num=0;//借阅记录条数
	char record[30][5];//图书借阅记录
	//这里为了方便，让同书共用一个编号
}BOOKS;

BOOKS bookk[1000];//一千本书
ADMIN adminn[1000];//一千名管理员
USERS userr[1000];//一千名用户

//【以下是读写文件操作】
void enter_user_file() {
	
	FILE *sc = fopen(UF, "r");
	fscanf(sc, "%d ", &user_cnt);
	int num = user_cnt;//<-这是一个flag
	for (int k = 0; k < num; k++) {
		fscanf(sc, "%s %s %d ",  userr[k].name,userr[k].ID, &userr[k].borrow_books_num);//<-这是读取id姓名和一个flag
		for (int i = 0; i < userr[k].borrow_books_num; i++)fscanf(sc,"%s ",userr[k].borrow_books[i]);
	}
	//cout << "完成读入用户文件！" << endl;
	fclose(sc);
}
void print_user_file() {
	FILE *fp=fopen(UF,"w");
	fprintf(fp,"%d ",user_cnt);
	int num = user_cnt;
	for (int k = 0; k < num; k++) {
		fprintf(fp, "%s %s %d ",  userr[k].name,userr[k].ID, userr[k].borrow_books_num);//打印ID、name、flag
		for (int i = 0; i < userr[k].borrow_books_num; i++) fprintf(fp, "%s ", userr[k].borrow_books[i]);
	}	
	//cout << "完成写入用户文件！" << endl;
	fclose(fp);
}
void enter_book_file() {
	FILE *sc1 = fopen(BF, "r");

	fscanf(sc1, "%d ", &book_cnt);//<-这是一个flag
	int num = book_cnt;
	for (int k = 0; k < num; k++) {
		fscanf(sc1, "%d %d %s %s %d ", &bookk[k].whole_num, &bookk[k].left_num,bookk[k].ID,bookk[k].name,&bookk[k].record_num);
		int num1 = bookk[k].record_num;
		//cout<<"enter_正确读入书文件"<<endl; 
		for (int i = 0; i < bookk[k].record_num; i++)fscanf(sc1,"%s ",bookk[k].record[i]);
	}
	//cout << "完成读入图书文件！" << endl;
	fclose(sc1);
}//注意格式！
void print_book_file() {
	FILE *fp1 = fopen(BF, "w");
	fprintf(fp1, "%d ", book_cnt);
	int num = book_cnt;
	for (int k = 0; k < num; k++) {
		fprintf(fp1, "%d %d %s %s %d ", bookk[k].whole_num, bookk[k].left_num,bookk[k].ID,bookk[k].name,bookk[k].record_num);
		for (int i = 1; i < bookk[k].record_num; i++)fscanf(fp1,"%s ",bookk[k].record[i]);
	}
	//cout << "完成写入图书文件！" << endl;
	fclose(fp1);
}
void enter_admin_file() {
	FILE *sc2 = fopen(AF, "r");
	fscanf(sc2, "%d ", &admin_cnt);
	int num = admin_cnt;
	for (int k = 0; k < num; k++)fscanf(sc2, "%s", adminn[k].ID);
	//cout << "完成读入管理员文件！" << endl;
	fclose(sc2);
}
void print_admin_file() {
	FILE *fp2 = fopen(AF, "w");
	fprintf(fp2, "%d ", admin_cnt);
	int num = admin_cnt;
	for (int k = 0; k < num; k++) fputs(adminn[k].ID, fp2);
	//cout << "完成写入管理员文件!" << endl;
	fclose(fp2);
}
//【over读写文件操作】

//初始化打开
void init_open() {
	enter_user_file();
	enter_book_file();
	enter_admin_file();
}
//保存
void save() {
	print_user_file();
	print_book_file();
	print_admin_file();
}
//找寻读者
int find_user(string ID_u) {
	int flag = 0;
	int i = 0;
	for (i = 0; i < user_cnt; i++) {
		flag = 0;
		if (!ID_u.compare(bookk[i].ID)) {
			flag = 1;
			break;
		}
	}
	if (!flag)return 0;
	return i;
}
//展示读者的个人信息
void show_user_infomation(int i) {
	int j = 0;
	cout << "以下为该用户信息：" << endl;
	cout << "【姓名        】" << userr[i].name << endl;
	cout << "【ID          】" << userr[i].ID << endl;
	cout << "【借阅书数    】" << userr[i].borrow_books_num << endl;
	cout << "【具体书目如下】" << endl;
	int num = userr[i].borrow_books_num;
	for (j = 0; num > 0; num--, j++)cout << userr[i].borrow_books[j] << endl;
}
//展示某本图书的信息
void show_book_infomation(int i) {
	cout << "以下为该本图书信息：" << endl;
	cout << "【书名        】" << bookk[i].name << endl;
	cout << "【ID          】" << bookk[i].ID << endl;
	cout << "【馆藏        】" << bookk[i].left_num << "/" << bookk[i].whole_num << endl;
	cout << "【借阅记录条数】" << bookk[i].record_num << endl;
}

//离开操作函数
void exitSystem() {
	cout << "期待与您的下次会面，回见。" << endl;
	system("pause");
	exit(0);//直接return 0 到main函数结束
}
//管理员的menu
void menu1(string ID_ad) {
	cout << "Dear administrator " << ID_ad << ",Welcome!" << endl;
	cout << "---------【请选择如下操作】--------" << endl;
	cout << "---------1.录入图书信息------------" << endl;
	cout << "---------2.修改图书信息------------" << endl;
	cout << "---------3.删除图书信息------------" << endl;
	cout << "---------4.录入用户信息------------" << endl;
	cout << "---------5.修改用户信息------------" << endl;
	cout << "---------6.删除用户信息------------" << endl;
	cout << "----------7.离开系统---------------" << endl;//√
}
//用户的menu
void menu2(string ID_u) {
	cout << "Dear user " << ID_u << ",Welcome!" << endl;
	//理想化是在这里插入读者的个人信息
	int i = find_user(ID_u);
	if (i)show_user_infomation(i);
	cout << "---------【请选择如下操作】-------" << endl;
	cout << "----------1.图书名称查询----------" << endl;
	cout << "----------2.借书------------------" << endl;
	cout << "----------3.还书------------------" << endl;
	cout << "----------4.离开系统--------------" << endl;//√
}

//录入图书信息,不需要flag
void log_book() {
	int booknum = 0;
	cout << "您好，请问您要录入几本图书？" << endl;
	cin >> booknum;

	for (int i = 1; i <= booknum; i++) {
		cout << "请输入第" << i << "本图书的馆藏数:" << endl;
		cin >> bookk[book_cnt].whole_num;
		bookk[book_cnt].left_num = bookk[book_cnt].whole_num;
		cout << "请输入第" << i << "本图书的名字:" << endl;
		cin >> bookk[book_cnt].name;
		cout << "请输入第" << i << "本图书的ID:(共五个数字)" << endl;
		cin >> bookk[book_cnt].ID;
		book_cnt++;
	}
	save();
	cout << "您已成功完成录入！" << endl;
	system("pause");
	system("cls");
}
//修改图书信息,已修改flag
void modify_book() {
	//int booknum = 0;
	int flag = 0;
	string bookid;
	int i = 0;
	int choice = 0;
	cout << "请输入您要修改书籍的编号：" << endl;
	cin >> bookid;
	for (i = 0; i < book_cnt; i++) {
		flag = 0;
		if (!bookid.compare(bookk[i].ID)) {
			flag = 1;
			break;
		}
	}
	if (!flag)cout << "查找失败，不存在这样编号的图书！" << endl;
	else
	{//得到了记录该书的下标！
		show_book_infomation(i);//展示一下该书信息
		cout << "修改操作：" << endl;
		cout << "1.修改书名" << endl;
		cout << "2.修改ID" << endl;
		cout << "3.修改馆藏" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入新书名：" << endl;
			cin >> bookk[i].name;
			break;
		case 2:
			cout << "请输入新ID：" << endl;
			cin >> bookk[i].ID;
			break;
		case 3:
			int orinalnum = bookk[i].whole_num;
			cout << "请输入馆藏数：" << endl;
			cin >> bookk[i].whole_num;
			bookk[i].left_num += (bookk[i].whole_num - orinalnum);
			break;
		}
		cout << "您已成功完成修改！" << endl;
		system("pause");
		system("cls");
	}save();
}
//删除图书信息,已修改flag
void delete_book() {
	string bookid;
	int i = 0;
	int flag = 0;
	cout << "请输入您要删除书籍的编号：" << endl;
	cin >> bookid;
	for (i = 0; i < book_cnt; i++) {
		flag = 0;
		if (!bookid.compare(bookk[i].ID)) {
			flag = 1; break;
		}
	}
	if (!flag)cout << "查找失败，不存在这样编号的图书！" << endl;
	else
	{
		for (; i < book_cnt; i++) {
			bookk[i].whole_num = bookk[i + 1].whole_num;
			bookk[i].left_num = bookk[i + 1].left_num;
			bookk[i].record_num = bookk[i + 1].record_num;
			strcpy(bookk[i].name, bookk[i + 1].name);
			strcpy(bookk[i].ID, bookk[i + 1].ID);
			for (int j = 0; j < bookk[i].record_num; i++) strcpy(bookk[i].record[j], bookk[i].record[j + 1]);
		}	
		book_cnt--;
		cout << "您已成功完成删除！" << endl;
		system("pause");
		system("cls");
	}save();
}
//录入用户信息,已修改flag
void log_user() {
	int usernum = 0;
	int k = 0;
	int flag = 0;
	string bookid;
	cout << "您好，请问您要录入几位用户？" << endl;
	cin >> usernum;
	for (int i = 1; i <= usernum; i++,user_cnt++) {
		cout << "请输入第" << i << "位用户的名字:" << endl;
		cin >> userr[user_cnt].name;
		cout << "请输入第" << i << "位用户的ID:(共5个数字)" << endl;
		cin >> userr[user_cnt].ID;
		cout << "请输入第" << i << "位用户借书数:" << endl;
		cin >> userr[user_cnt].borrow_books_num;
		if (userr[user_cnt].borrow_books_num == 0)continue;
		else {
			int num = userr[user_cnt].borrow_books_num;

			for (int j = 0; j < num; j++) {
				cout << "请输入第" << (j + 1) << "本书籍的编号：" << endl;
				cin >> bookid;
				for (k = 0; k < book_cnt; k++) {
					if (!bookid.compare(bookk[k].ID)) {
						flag = 1;
						break;
					}
					flag = 0;
				}
				if (!flag)cout << "查找失败，不存在这样编号的图书！" << endl;
				else {
					bookk[k].left_num--;
					strcpy(bookk[k].record[bookk[k].record_num],userr[user_cnt].ID);
					cout<<"[K]"<<k<<" [bookk[k].record_num]"<<bookk[k].record_num<<" [userr[user_cnt].ID]"<<userr[user_cnt].ID<<endl;
					bookk[k].record_num++;
					const char * s = bookid.c_str();
					strcpy(userr[i].borrow_books[j], s);
				//	cout<<"6|||"<<endl;
				}
			}
		}
	}
	save();
	cout << "您已成功完成录入！" << endl;
	system("cls");
}
//函数内子函数，修改用户的借阅记录书【*】
void modify_user_borrow_book(int i) {
	int tip = 0;
	int flag = 0;
	int j = 0;
	int k = 0;
	string bookid;
	//先把所有借了的书还原
	for (; tip < userr[i].borrow_books_num; tip++) {
		for (j = 0; j < book_cnt; j++) {
			flag = 0;
			if (!strcmp(userr[i].borrow_books[tip], (bookk[j].ID))) {
				flag = 1;
				break;
			}
		}
		if (!flag)continue;
		else {
			cout<<"success modify book"<<endl; 
			bookk[j].left_num++;
		}
	}
	//再重新进入记录中
	cout << "请先输入新的借阅书数：" << endl;
	cin >> userr[i].borrow_books_num;
	int num = userr[i].borrow_books_num;
	for (int j = 0; j < num; j++) {
		cout << "请输入第" << (j + 1) << "本图书的编号：" << endl;
		cin >> bookid;
		for (k = 0; k < book_cnt; k++) {
			flag = 0;
			if (!bookid.compare(bookk[k].ID)) {
				flag = 1;
				break;
			}
		}
		if (!flag)continue;
		else {
			bookk[k].left_num--;
			strcpy(bookk[k].record[bookk[k].record_num],userr[i].ID);
			bookk[k].record_num++;
		}
	}
}
//修改用户信息,已修改flag
void modify_user() {
	//int booknum = 0;
	string userid;
	string bookid;
	int i = 0;
	int flag = 0;
	int choice = 0;
	cout << "请输入您要修改用户的ID：" << endl;
	cin >> userid;
	for (i = 0; i < user_cnt; i++) {
		if (!userid.compare(userr[i].ID)) {
			flag = 1;
			break;
		}
		flag = 0;
	}
	if (!flag)cout << "查找失败，不存在这样ID的用户！" << endl;
	else
	{//得到了记录该用户的下标！
		show_user_infomation(i);//展示一下该用户信息
		cout << "修改操作：" << endl;
		cout << "1.修改姓名" << endl;
		cout << "2.修改ID" << endl;
		cout << "3.修改借阅书籍" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入新姓名：" << endl;
			cin >> userr[i].name;
			break;
		case 2:
			cout << "请输入新ID：" << endl;
			cin >> userr[i].ID;
			break;
		case 3:
			modify_user_borrow_book(i);
			break;
		default:
			break;
		}
		cout << "您已成功完成修改！" << endl;
		system("cls");
	}	save();
}
//删除用户信息
void delete_user() {
	string userid;
	int i = 0;
	int flag = 0;

	cout << "请输入您要删除用户的ID：" << endl;
	cin >> userid;
	for (i = 0; i < user_cnt; i++) {
		flag = 0;
		if (!userid.compare(userr[i].ID)) {
			flag = 1;
			break;
		}
	}
	if (!flag)cout << "查找失败，不存在这样编号的用户！" << endl;
	else
	{
		if(userr[i].borrow_books_num!=0){
			cout<<"该用户有未归还的书籍！不允许删除！"<<endl;
			return; 
		}else{
			for (; i < user_cnt; i++) {//修改数据
			userr[i].borrow_books_num = userr[i + 1].borrow_books_num;
			strcpy(userr[i].name, userr[i + 1].name);
			strcpy(userr[i].ID, userr[i + 1].ID);
			for (int j = 0; j < userr[i].borrow_books_num; i++) strcpy(userr[i].borrow_books[j], userr[i].borrow_books[j + 1]);
			}
			user_cnt--;
			cout << "您已成功完成删除！" << endl;
			system("cls");
			save();
			}
	}
}

void ad_main(string id) {//管理员操作的主页面
	int choice = 0;
	while (true) {
		menu1(id);
		cin >> choice;
		switch (choice)
		{
		case 1: log_book();//录入图书信息
			break;
		case 2:modify_book();//修改图书信息
			break;
		case 3:delete_book();//删除图书信息
			break;
		case 4:log_user();//录入用户信息
			break;
		case 5:modify_user();//修改用户信息
			break;
		case 6:delete_user();//删除用户信息
			break;
		case 7:exitSystem();//离开系统
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}

int isAd(string id) {//判定该编号是否可以对的上管理员
	for (int i = 0; i < admin_cnt; i++) {
		if (!id.compare(adminn[i].ID))return 1;
	}
	return 0;//0表示匹配不上
}

//图书名称查询
void search_book() {
	string bookid;
	int flag = 0;
	int i = 0;
	cout << "请输入所要查询的图书编号" << endl;
	cin >> bookid;
	for (i = 0; i < book_cnt; i++) {
		flag = 0;
		if (!bookid.compare(bookk[i].ID)) {
			flag = 1;
			break;
		}
	}
	if (!flag)cout << "查询图书不存在！" << endl;
	else show_book_infomation(i);
	system("pause");
	system("cls");
}
//借书
void wanna_borrow_book(int i) {
	string bookid;
	int flag = 0;
	int j = 0;
	cout << "请输入想要借的书的编号：" << endl;
	cin >> bookid;
	for (j = 0; j < book_cnt; j++) {
		flag = 0;
		if (!bookid.compare(bookk[j].ID)) {
			flag = 1;
			break;
		}
	}
	if (!flag)cout << "想借图书不存在！" << endl;
	else {//看余量还有没有
		if (bookk[j].left_num > 0) {
			cout << "借书成功！请两个月内归还！！！" << endl;
			bookk[j].left_num--;
			//用户借阅记录要有所表示
			const char * s = bookid.c_str();
			strcpy(userr[i].borrow_books[userr[i].borrow_books_num], s);
			userr[i].borrow_books_num++;
			//图书的借阅记录
			strcpy(bookk[j].record[bookk[j].record_num],userr[i].ID);
			bookk[j].record_num++; 
		}else{
			cout<<"sorry.该书已全部借出。借书失败。"<<endl;
			return; 
		}
	}
	save();
	system("pause");
	system("cls");
}
//还书
void wanna_return_book(int i) {
	string bookid;
	int flag = 0;
	int j = 0;//该书在user里面的下标
	int k = 0;//该书在图书馆中的标
	cout << "请输入想要还的书的编号：" << endl;
	cin >> bookid;
	for (j = 0; j < user_cnt; j++) {
		flag = 0;
		if (!bookid.compare(userr[i].borrow_books[j])) {
			flag = 1;
			break;
		}
	}
	if (!flag)cout << "该图书不存在！" << endl;
	else {//归还
		for (; j < userr[i].borrow_books_num; j++)strcpy(userr[i].borrow_books[j], userr[i].borrow_books[j + 1]);
		userr[i].borrow_books_num--;
		//更新在图书系统内信息
		for (k = 0; k < book_cnt; k++) {
			if (!bookid.compare(bookk[k].ID)) {
				bookk[k].left_num++;
				break;
			}
		}
	}
	save();
	cout << "成功还书！" << endl;
	system("pause");
	system("cls");
}

void u_main(string id) {//用户操作的主界面
	int choice = 0;
	int i = find_user(id);
	while (true) {
		menu2(id);
		cin >> choice;
		switch (choice)
		{
		case 1:search_book();//图书名称查询
			break;
		case 2:wanna_borrow_book(i);//我想借书
			break;
		case 3:wanna_return_book(i);//我想还书
			break;
		case 4:exitSystem();//离开系统
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}

int isU(string id) {//判定该编号是否对的上用户
	for (int i = 0; i < user_cnt; i++) {
		if (!id.compare(userr[i].ID))return 1;
	}
	return 0;//0表示匹配不上
}

int main(int argc, char *argv[]) {
	system("color B0");
	cout << "欢迎使用图书馆管理系统！" << endl;
	//判定输入的用户名是否正确，即可以查找到该人信息
	//如果正确查找到，转入菜单
	init_open();
	string id = argv[2];
	if (!strcmp(argv[1], "-a")) {//判定是否为管理员
		if (isAd(id))ad_main(argv[2]);
		else  cout << "error！" << endl;
	}
	if (!strcmp(argv[1], "-u")) {//判定是否为用户
		if (isU(id))u_main(argv[2]);
		else  cout << "error！" << endl;
	}
	return 0;
}
