using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication2
{
    class Member
    {
        private string id;
        private string pwd;
        private string name;
        private string email;
        public Member() { }
        public Member(string id, string pwd, string name,
            string email)
        {
            this.id = id;
            this.pwd = pwd;
            this.name = name;
            this.email = email;
        }
        public void setId(string id)
        {
            this.id = id;
        }
        public string getId()
        {
            return id;
        }
        public void setPwd(string pwd)
        {
            this.pwd = pwd;
        }
        public string getPwd()
        {
            return pwd;
        }
        public void setName(string name)
        {
            this.name = name;
        }
        public string getName()
        {
            return name;
        }
        public void setEmail(string email)
        {
            this.email = email;
        }
        public string getEmail()
        {
            return email;
        }
        public override string ToString()
        {
            return "id:" + id + ", pwd:" + pwd + ", name:" + name + ", email:"
                + email;
        }
    }
    interface Dao
    {
        void insert(Member m);
        int selectById(string id);
        Member selectByIdx(int idx);
        void update(Member m);
        void delete(string id);
    }
    class DaoImpl : Dao
    {
        private Member[] data;
        private int cnt;
        public DaoImpl()
        {
            data = new Member[30];
        }
        public void insert(Member m)
        {
            data[cnt++] = m;
        }
        public int selectById(string id)
        {
            for (int i = 0; i < cnt; i++)
            {
                if (id.Equals(data[i].getId()))
                {
                    return i;
                }
            }
            return -1;
        }
        public Member selectByIdx(int idx)
        {
            return data[idx];
        }
        public void update(Member m)
        {
            int idx = selectById(m.getId());
            if (idx < 0)
            {
                Console.WriteLine("없는 아이디");
                return;
            }
            data[idx].setPwd(m.getPwd());
            data[idx].setEmail(m.getEmail());
            Console.WriteLine("수정이 완료되었음");
            Console.WriteLine(data[idx]);
        }
        public void delete(string id)
        {
            int idx = selectById(id);
            if (idx < 0)
            {
                Console.WriteLine("없는 아이디");
                return;
            }
            for (int i = idx; i < cnt - 1; i++)
            {
                data[i] = data[i + 1];
            }
            cnt--;
        }
    }
    interface Service
    {
        void join();
        bool login();
        void logout();
        void memberOut();
        void editInfo();
    }
    class ServiceImpl : Service
    {
        private Dao dao;
        public static string loginId = "";
        public ServiceImpl(Dao dao)
        {
            this.dao = dao;
        }
        public void join()
        {
            Member m = new Member();
            while (true)
            {
                Console.Write("id:");
                m.setId(Console.ReadLine());
                if (dao.selectById(m.getId()) < 0)
                {
                    break;
                }
                else
                {
                    Console.WriteLine("id 중복. 다시 입력하라");
                }
            }
            Console.Write("pwd:");
            m.setPwd(Console.ReadLine());
            Console.Write("name:");
            m.setName(Console.ReadLine());
            Console.Write("email:");
            m.setEmail(Console.ReadLine());
            dao.insert(m);
        }
        public bool login()
        {
            string id = "";
            string pwd = "";
            Console.Write("id:");
            id = Console.ReadLine();
            Console.Write("pwd:");
            pwd = Console.ReadLine();
            int idx = dao.selectById(id);
            if (idx < 0)
            {
                Console.WriteLine("아이디 불일치");
                return false;
            }
            Member m = dao.selectByIdx(idx);
            if (pwd.Equals(m.getPwd()))
            {
                loginId = id;
                return true;
            }
            else
            {
                Console.WriteLine("패스워드 불일치");
            }
            return false;
        }
        public void logout()
        {
            if (loginId.Equals(""))
            {
                Console.WriteLine("로그인 먼저");
            }
            else
            {
                loginId = "";
            }
        }
        public void memberOut()
        {
            if (loginId.Equals(""))
            {
                Console.WriteLine("로그인 먼저");
            }
            else
            {
                dao.delete(loginId);
                loginId = "";
            }
        }
        public void editInfo()
        {
            string newPwd = "";
            string newEmail = "";

            if (loginId.Equals(""))
            {
                Console.WriteLine("로그인 먼저");
            }
            else
            {
                Member m2 = dao.selectByIdx(dao.selectById(loginId));
                Console.WriteLine("현재 내정보");
                Console.WriteLine(m2);
                Console.Write("new pwd:");
                newPwd = Console.ReadLine();
                Console.Write("new email:");
                newEmail = Console.ReadLine();
                Member m = new Member(loginId, newPwd, null, newEmail);
                dao.update(m);
                m2 = dao.selectByIdx(dao.selectById(loginId));
                Console.WriteLine("수정된 내정보");
                Console.WriteLine(m2);
            }
        }
    }
    class Article
    {
        private int num;
        private string writer;
        private string title;
        private string content;
        public Article() { }
        public Article(int num, string writer, string title, string content)
        {
            this.num = num;
            this.writer = writer;
            this.title = title;
            this.content = content;
        }
        public void setNum(int num)
        {
            this.num = num;
        }
        public int getNum()
        {
            return num;
        }
        public void setWriter(string writer)
        {
            this.writer = writer;
        }
        public string getWriter()
        {
            return writer;
        }
        public void setTitle(string title)
        {
            this.title = title;
        }
        public string getTitle()
        {
            return title;
        }
        public void setContent(string content)
        {
            this.content = content;
        }
        public string getContent()
        {
            return content;
        }
        public override string ToString()
        {
            return "num:" + num + ", writer:" + writer + ", title:" + title +
                ", content:" + content;
        }
    }
    interface ArticleDao
    {
        void insert(Article a);
        int selectByNum(int num);
        Article selectByIdx(int idx);
        Article[] selectAll();
        void update(Article a);
        void delete(int num);
    }
    class ArticleDaoImpl : ArticleDao
    {
        private Article[] data;
        private int cnt;
        private int cnt_article;
        public int getCnt()
        {
            return cnt;
        }
        public ArticleDaoImpl()
        {
            data = new Article[30];
        }
        public void insert(Article a)
        {
            a.setNum(++cnt_article);
            data[cnt++] = a;
        }
        public int selectByNum(int num)
        {
            for (int i = 0; i < cnt; i++)
            {
                if (num == data[i].getNum())
                {
                    return i;
                }
            }
            return -1;
        }
        public Article selectByIdx(int idx)
        {
            return data[idx];
        }
        public Article[] selectAll()
        {
            return data;
        }
        public void update(Article a)
        {
            int idx = selectByNum(a.getNum());
            if (idx < 0)
            {
                Console.WriteLine("없는 글");
                return;
            }
            data[idx].setTitle(a.getTitle());
            data[idx].setContent(a.getContent());
        }
        public void delete(int num)
        {
            int idx = selectByNum(num);
            if (idx < 0)
            {
                Console.WriteLine("없는 글");
                return;
            }
            for (int i = idx; i < cnt - 1; i++)
            {
                data[i] = data[i + 1];
            }
            cnt--;
        }
    }
    class ArticleService
    {
        private ArticleDao dao;

        public ArticleService(ArticleDao dao)
        {
            this.dao = dao;
        }
        public void addArticle()
        {
            if (ServiceImpl.loginId.Equals(""))
            {
                Console.WriteLine("로그인먼저");
            }
            else
            {
                Article a = new Article();
                Console.Write("title:");
                a.setTitle(Console.ReadLine());
                Console.Write("content:");
                a.setContent(Console.ReadLine());
                a.setWriter(ServiceImpl.loginId);
                dao.insert(a);
            }
        }
        public void getArticle()
        {
            int num = 0;
            Console.Write("글번호:");
            num = Int32.Parse(Console.ReadLine());
            int idx = dao.selectByNum(num);
            if (idx < 0)
            {
                Console.WriteLine("없는 글");
                return;
            }
            Article a = dao.selectByIdx(idx);
            Console.WriteLine(a);
        }
        public void editArticle()
        {
            if (ServiceImpl.loginId.Equals(""))
            {
                Console.WriteLine("로그인먼저");
                return;
            }
            int num = 0;
            Console.Write("글번호:");
            num = Int32.Parse(Console.ReadLine());
            int idx = dao.selectByNum(num);
            if (idx < 0)
            {
                Console.WriteLine("없는 글");
                return;
            }
            Article a = dao.selectByIdx(idx);
            if (a.getWriter().Equals(ServiceImpl.loginId))
            {
                Console.Write("new title:");
                a.setTitle(Console.ReadLine());
                Console.Write("new content:");
                a.setContent(Console.ReadLine());
                //dao.update(a);
            }
            else
            {
                Console.WriteLine("로그인 아이디와 작성자 불일치");
            }
        }
        public void delArticle()
        {
            if (ServiceImpl.loginId.Equals(""))
            {
                Console.WriteLine("로그인먼저");
                return;
            }
            int num = 0;
            Console.Write("글번호:");
            num = Int32.Parse(Console.ReadLine());
            int idx = dao.selectByNum(num);
            if (idx < 0)
            {
                Console.WriteLine("없는 글");
                return;
            }
            Article a = dao.selectByIdx(idx);
            if (a.getWriter().Equals(ServiceImpl.loginId))
            {
                dao.delete(num);
            }
            else
            {
                Console.WriteLine("로그인 아이디와 작성자 불일치");
            }
        }
        public void printArticles()
        {
            Article[] data = dao.selectAll();
            int cnt = ((ArticleDaoImpl)dao).getCnt();
            for (int i = 0; i < cnt; i++)
            {
                Console.WriteLine(data[i]);
            }
        }
    }
    class Program
    {
        static void func1(ServiceImpl service)
        {
            bool flag = true;
            int menu;
            while (flag)
            {
                Console.WriteLine("1.회원가입 2.로그인 3.내정보수정 4.로그아웃 5.탈퇴 6.종료");
                menu = Int32.Parse(Console.ReadLine());
                switch (menu)
                {
                    case 1:
                        service.join();
                        break;
                    case 2:
                        service.login();
                        break;
                    case 3:
                        service.editInfo();
                        break;
                    case 4:
                        service.logout();
                        break;
                    case 5:
                        service.memberOut();
                        break;
                    case 6:
                        flag = false;
                        break;
                }
            }

        }
        static void func2(ArticleService service)
        {
            bool flag = true;
            int menu;
            while (flag)
            {
                Console.WriteLine("1.글쓰기 2.글검색 3.글수정 4.글삭제 5.글목록 6.종료");
                menu = Int32.Parse(Console.ReadLine());
                switch (menu)
                {
                    case 1:
                        service.addArticle();
                        break;
                    case 2:
                        service.getArticle();
                        break;
                    case 3:
                        service.editArticle();
                        break;
                    case 4:
                        service.delArticle();
                        break;
                    case 5:
                        service.printArticles();
                        break;
                    case 6:
                        flag = false;
                        break;
                }
            }

        }
        static void Main(string[] args)
        {
            ServiceImpl service = new ServiceImpl(new DaoImpl());
            ArticleService service2 =
                new ArticleService(new ArticleDaoImpl());
            bool flag = true;
            int menu;
            while (flag)
            {
                Console.WriteLine("1.회원관리 2.게시판 3.종료");
                menu = Int32.Parse(Console.ReadLine());
                switch (menu)
                {
                    case 1:
                        func1(service);
                        break;
                    case 2:
                        func2(service2);
                        break;
                    case 3:
                        flag = false;
                        break;
                }
            }
        }
    }
}
//interface - 추상메서드로만 구성된 클래스. 다중상속가능