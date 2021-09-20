# -*- coding: utf-8 -*-
"""
Created on Mon Sep 20 16:03:39 2021

@author: Meow Van
"""

# 获取弹幕
from bilibili_api import video
from bs4 import BeautifulSoup
import csv
import time
import pandas as pd

# 参数：视频BV号 
BVID = "BV17J41197uD"

# 获取视频信息
info = video.get_video_info(bvid=BVID)

# 假设这里获取 p1 的最新弹幕信息，需要取出 page_id，即每 p 都有自己的编号
page_id = info["pages"][0]["cid"]

# 然后开始获取弹幕
danmakus = video.get_danmaku(bvid=BVID, page_id=page_id)

dm_dict = {'Danmakus':'Danmakus','Time':'Time','Dm_time':'DmTime'}

#运行前请删除原来的 Bilibili_Danmakus.csv 文件
with open('../Data/Bilibili/Bilibili_Danmakus.csv','a',encoding='utf-8-sig',newline='') as f: 
    w = csv.writer(f)
    w.writerow(dm_dict.keys())
    for dm in danmakus:
        dm_dict['Danmakus'] = dm.text
        dm_dict['Time'] = dm.send_time
        dm_dict['Dm_time'] = dm.dm_time
        w.writerow(dm_dict.values())
