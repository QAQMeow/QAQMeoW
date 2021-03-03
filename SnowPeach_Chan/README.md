数据来源
===

1. 电影《芙蓉镇》Bilibili 弹幕视频网站 2021 年 1 月 22 日前弹幕，总计 6430 条。《芙
蓉镇》B 站地址：
https://www.bilibili.com/bangumi/play/ss29320/?from=search&seid=3521018161178944183
2. 豆瓣网电影《芙蓉镇》部分短评共 488 条，及对应评分，评分分五个类别：力荐，
推荐，还行，较差，很差，对应 5 到 1 颗星。《芙蓉镇》豆瓣地址：
https://movie.douban.com/subject/1297880/

分析过程
===

（一）
1. 对弹幕进行拆分提词，得到字数从 0 到 29 不等的词共 48371 个。
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/WordsDistribution.png" width="960" height="540" >

2. 在去掉如“啊”，“那个”，“哈哈哈”等对词云分析造成误导的词语后，根据各词出现的频率制作图云，词语字体越大，出现频率越高。
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/Pic0.png" width="960" height="540" >

3. 选择词语长度为 2，3，4，5，6，7，8 分别制作词云。

##### 词长为2
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/L2.png" width="960" height="540" >

##### 词长为3
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/L3.png" width="960" height="540" >

##### 词长为4
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/L4.png" width="960" height="540" >

##### 词长为5
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/L5.png" width="960" height="540" >

##### 词长为6
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/L6.png" width="960" height="540" >

##### 词长为7
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/L7.png" width="960" height="540" >

##### 词长为8
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/L8.png" width="960" height="540" >


（二）
1． 使用豆瓣评论作为训练集，B 站弹幕作为测试集进行 LSTM 神经网络机器学习，依据豆瓣评论对 B 站弹幕进行分类。<br/>
2． CPU 为Inter(R) i5-8300H,主频2.3GHz，RAM为16GB，基于深度学习框架Tensorflow,实验编程语言 Python3.7。<br/>
3． 参数设置：单层 LSTM10 个节点神经网络，选择均方误差作为损失函数，设置参数更新方法为 Adam，其他默认。训练次数 50 次，选择 33%的豆瓣评论作为验证集。<br/>
4． 结果：训练结束后均方误差下降到 0.00027，验证集正确率稳定在 0.648。<br/>
5． 使用模型对 B 站弹幕进行分类，得到各分类概率，取其平均得到平均概率。

<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result/ProbabilityDistribution.png">











