# library-bag-cabinet-system

软件用codeblocks、vscode有C++环境即可，数据库（mysql）推荐Navicat

基于C++下的图书馆书包柜管理系统，主要功能链接到数据库实现对图书馆书包柜的预约以及信息录入，有添加预约信息功能、预约信息修改功能、预约信息删除功能、预约信息查找功能、预约信息显示功能。

![image](https://user-images.githubusercontent.com/79844631/194097585-776b1385-971e-4838-a38c-1eca2eb22ea7.png)

（1）添加功能：程序能够任意添加学生预约信息的记录，要求学生的学号要唯一，如果添加了重复编号的记录时，则提示数据添加重复并取消添加。

![image](https://user-images.githubusercontent.com/79844631/194093679-f4c7cbc6-7055-4008-8477-42c0c9c2c4b8.png)
![image](https://user-images.githubusercontent.com/79844631/194093708-1e6594e1-7c69-4dd5-9832-3533db8b83b6.png)

（2）修改功能：可以将学号、姓名等信息对已添加的记录进行修改。

![image](https://user-images.githubusercontent.com/79844631/194093744-c8d148e5-dd12-4980-a2cb-02f41b0b2eb5.png)
![image](https://user-images.githubusercontent.com/79844631/194093764-021f6c59-8f39-435a-9361-bce6eba1e1fb.png)

（3）删除功能：主要实现对已添加学生预约信息记录进行删除。如果当前系统中没有相应的学生预约信息记录，则提示“记录为空！”并返回操作；否则，输入要删除的学生的学号或姓名，根据所输入的信息删除该学生预约记录，如果没有找到该学生预约记录，则提示相应的记录不存。

![image](https://user-images.githubusercontent.com/79844631/194093801-4c458802-7e73-4383-adce-948a536a05ae.png)
![image](https://user-images.githubusercontent.com/79844631/194093815-40bccf52-4888-4182-9c13-6d2e7991b07d.png)

（4）查询功能：可根据学号、姓名等信息对已添加的记录进行查询，如果未找到，给出相应的提示信息，如果找到，则显示相应的记录信息。

1.按学号查询

![image](https://user-images.githubusercontent.com/79844631/194093844-63f4d3fd-258d-45fb-ade2-58f265c61fc9.png)

2.按姓名

![image](https://user-images.githubusercontent.com/79844631/194093922-22dfd134-67d2-4087-86a2-a5cb6ff6d662.png)

3.按专业

![image](https://user-images.githubusercontent.com/79844631/194093970-e39488d4-fc1d-4508-8998-edc56568aeae.png)

（5）显示功能：可显示当前系统中所有记录，每条记录占据一行。

![image](https://user-images.githubusercontent.com/79844631/194094002-710b518b-da6f-4942-bcf7-fbbf9d0e3435.png)



