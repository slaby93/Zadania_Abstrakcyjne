using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication51
{
    class Program
    {
        class Person
        {
            public string Name { get; set; }
            public string Surname { get; set; }
            public string Id { get; set; }
            public Person(string imie, string nazwisko, string id)
            {
                this.Name = imie;
                this.Surname = nazwisko;
                this.Id = id;
            }
        }

        class Student : Person
        {
            IList<Course> currentCourses = new List<Course>();
            public Student(string imie, string nazwisko, string id) : base(imie, nazwisko, id) { }
            public IList<Course> CurrentCourses
            {
                get
                {
                    return this.currentCourses;
                }
            }
        }

        class Teacher : Person
        {
            IList<Course> coursesTaught = new List<Course>();
            public Teacher(string imie, string nazwisko, string id) : base(imie, nazwisko, id) { }
            public IList<Course> CoursesTaught
            {
                get
                {
                    return this.coursesTaught;
                }
            }
        }

        class Course
        {
            IList<Teacher> teachers = new List<Teacher>();
            IList<Student> students = new List<Student>();
            public Course(string name)
            {
                this.Name = name;
            }
            public string Name
            {
                get;
                set;
            }
            public void AddTeacher(Teacher t)
            {
                if (!Teachers.Contains(t))
                {
                    Teachers.Add(t);
                }
                t.CoursesTaught.Add(this);
            }
            public void AddStudent(Student s)
            {
                if (!students.Contains(s))
                {
                    students.Add(s);
                }
                s.CurrentCourses.Add(this);
            }
            public IList<Teacher> Teachers
            {
                get
                {
                    return this.teachers;
                }
            }
            public IList<Student> Students
            {
                get
                {
                    return this.students;
                }
            }
        }

        static void Main(string[] args)
        {
            Teacher[] teachers = { new Teacher("Zygmunt", "Nowak", "356"), new Teacher("Anna", "Kowalska", "124"), new Teacher("Jan", "Wiśniewski", "045") };
            Student[] students = { new Student("Tekla", "Dąbrowska", "4445"), new Student("Renata", "Lewandowska", "1528"), new Student("Rafał", "Wójcik", "9031"), new Student("Bogusław", "Kamiński", "1116"), new Student("Tomasz", "Abramowiec", "1024"), new Student("Zofia", "Nowarz", "3313") };

            IList<Course> courses = new List<Course>();
            courses.Add(new Course("Farmakologia"));
            courses[0].AddTeacher(teachers[0]);
            courses[0].AddStudent(students[0]);
            courses[0].AddStudent(students[1]);
            courses[0].AddStudent(students[4]);
            courses[0].AddStudent(students[5]);

            courses.Add(new Course("Neurobiologia"));
            courses[1].AddTeacher(teachers[1]);
            courses[1].AddStudent(students[0]);
            courses[1].AddStudent(students[1]);

            courses.Add(new Course("Fizjologia z patofizjologią"));
            courses[2].AddTeacher(teachers[1]);
            courses[2].AddTeacher(teachers[2]);
            courses[2].AddStudent(students[2]);
            courses[2].AddStudent(students[3]);
            courses[2].AddStudent(students[5]);

            var nameQuery =
                from c in courses
                from s in c.Students
                where c.Students.Count > 2 && s.Surname[s.Surname.Length - 1] == 'a'
                group s by s.Id into studentOccurances
                select studentOccurances.First().Name + " " + studentOccurances.First().Surname;

            foreach (var v in nameQuery)
            {
                System.Console.WriteLine(v);
            }

            var methodNameQuery = courses
                .Where(course => course.Students.Count > 2)
                .SelectMany(course => course.Students)
                .Where(student => student.Surname[student.Surname.Length - 1] == 'a')
                .GroupBy(t => t.Id, (str, grp) => { Student t = grp.First(); return t.Name + " " + t.Surname; });

            foreach (var v in methodNameQuery)
            {
                System.Console.WriteLine(v);
            }

            var methodCountQuery = courses
                .Where(course => course.Students.Count > 2)
                .SelectMany(course => course.Students)
                .Where(student => student.Surname[student.Surname.Length - 1] == 'a')
                .GroupBy(t => t.Id, (str, grp) => { Student t = grp.First(); return t.Name + " " + t.Surname; })
                .Aggregate(1, (multiply, student) => multiply * student.Count(x => x == 'a'));

            System.Console.WriteLine(methodCountQuery);

            Console.ReadLine();
        }
    }
}
