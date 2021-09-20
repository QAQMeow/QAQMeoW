<<<<<<< HEAD
=======
2021.5.17更新
===

__1. 由于b站弹幕接口进行了更新，原先接口被废弃了，改成了这个:https://api.bilibili.com/x/v2/dm/web/seg.so 原有的通过直接访问API弹幕爬虫方法全部失效__</br>
__参考https://www.bilibili.com/read/cv9762979 所提供的方法对弹幕爬取脚本进行更新__
__以后爬取弹幕只要提供视频Bv号即可（提取的应该时当日之前的弹幕）__</br>
__（非常感谢这位大佬提供的库，舔舔大佬的脚后跟PRPRPR）__</br>
__2. 提取的数据增加了弹幕发送时间，弹幕在电影中的时间,提取的时间为2021.5.17，所以弹幕数量也增加了__ </br>
__3.生成词云没有较大改变，删去LSMT神经网络分类，删去了豆瓣评论，以及相关结果，增加弹幕时间分布__ </br>
__4. 脚本精简为两个部分 弹幕获取（GetDanmakus.ipynb） 数据分析__（DataAnalysis.ipynb） </br>
__5.数据分析分为三部分 生成词云 弹幕频率分布 弹幕时间分布__ <br>
__6. 其他参见脚本注释__

词云
==
__词云没有较大变化__
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result2/Pic0.png" width="960" height="540" >

弹幕频率分布
==
__弹幕频率分布图几乎没有变化，对图的视觉效果进行了更新__
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result2/Words_Distribution.png" width="800" height="500" >

弹幕时间分布
==
_——新增弹幕时间分布
统计每分钟内的弹幕数，可以看到在电影0，35，83分钟时分别达到三次弹幕数量高峰随后呈下降趋势，推测与电影情节以及统计间隔有关（统计间隔为30s,60,90s,120s时弹幕数量高峰并不相同，未作图）__
<img src="https://github.com/QAQMeow/QAQMeow/blob/master/SnowPeach_Chan/Result2/DanmakusPerMin.png" width="800" height="500" >

2021.5.17
==
此次更新为最后一次较大更新，之后会添加一些脚本注释</br>
ﾚ(ﾟ∀ﾟ;)ﾍ=З=З=З，溜了溜了
==

2021.6.25
==
拜拜


参考
=
https://www.bilibili.com/read/cv9762979 </br>
https://github.com/Passkou/bilibili_api </br>
https://www.zhihu.com/question/381784377/answer/1099438784  </br>
概率论与数理统计：第九版 Probability and  Statistics for Engineers ,Ninth Edition: / (美)理查德·A·约翰逊(Richard A.Johson)著.--北京：电子工业出版社，2017.8 ISBN 978-7-121-31971-6 </br>
中国传统色：故宫里的色彩美学 / 郭浩，李健明著.--北京：中信出版社，2020.10（2021.2重印）ISBN 978-7-5217-1605-4
>>>>>>> a27471bf50696adfd45fb8682abb02f46ae1b2c6
