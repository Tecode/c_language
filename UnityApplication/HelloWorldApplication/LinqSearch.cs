using System;
using System.Collections.Generic;
using System.Linq;

namespace HelloWorldApplication
{
    public class LinqSearch
    {
        public static void Run()
        {
            var catList = new List<Cat>
            {
                new Cat { Id = 1001, Name = "加菲猫", Age = 2 },
                new Cat { Id = 1002, Name = "汤姆猫", Age = 20 },
                new Cat { Id = 1003, Name = "梨花猫", Age = 4 },
                new Cat { Id = 1004, Name = "加菲猫", Age = 12 },
                new Cat { Id = 1005, Name = "加菲猫", Age = 1 },
                new Cat { Id = 1006, Name = "加菲猫", Age = 0.5f }
            };

            var mouseList = new List<Mouse>
            {
                new Mouse { CatId = 1002, Name = "米老鼠" },
                new Mouse { CatId = 1003, Name = "风车车" },
                new Mouse { CatId = 1004, Name = "洛可可" }
            };

            // LINQ查询1
            // var result = from data in catList
            //     where data.Age > 2
            //     orderby data.Age descending
            //     select data.Name;
            // result.ToList().ForEach(value => Console.WriteLine(value.ToString()));

            // LINQ查询2
            // catList.Where(data => data.Age > 2).ToList().ForEach(Console.WriteLine);

            // LINQ联合查询
            // var unitedResult = from cat in catList
            //     from mouse in mouseList
            //     where mouse.CatId == cat.Id
            //     select new { mouse, cat };
            // Console.WriteLine(unitedResult.ToList().Count);

            // 联合查询使用方法查询
            // catList.SelectMany(data => mouseList, (cat, mouse) => new { mouse, cat })
            //     // 倒序排
            //     .OrderByDescending(data => data.cat.Age)
            //     .ThenBy(data => data.cat.Name)
            //     .Where(data => data.cat.Id == data.mouse.CatId).ToList()
            //     .ForEach((value) => Console.WriteLine(value.cat.ToString()));

            // join查询
            var result = from cat in catList
                join mouse in mouseList on cat.Id equals mouse.CatId
                select new { cat, mouse };
            result.ToList().ForEach(vale => Console.WriteLine(vale.ToString()));
            
            // var haveValue = catList.Any(cat => cat.Age > 2);
            var haveValue = catList.All(cat => cat.Age > 2);
            Console.WriteLine(haveValue);

            // { Cat = ID: 1002, Name: 汤姆猫, Age: 20, Mouse = CatId:1002, Name:米老鼠 }
            // { Cat = ID: 1003, Name: 梨花猫, Age: 4, Mouse = CatId:1003, Name:风车车 }
            // { Cat = ID: 1004, Name: 加菲猫, Age: 12, Mouse = CatId:1004, Name:洛可可 }
        }
    }
}