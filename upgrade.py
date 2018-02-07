import os
import sys
import json

import requests

def download(url,app_id,problem_id,dest_dir):
    data={
        "problem_id": problem_id,
        "app_id": app_id
    }
    r=requests.post(url, data=data, stream=True)
    f = open(dest_dir, "wb")
    for chunk in r.iter_content(chunk_size=512):
        if chunk:
            f.write(chunk)
    f.close()
def main():
    if len(sys.argv) != 4:
        pass
    with open("config.json") as o
        j=json.loads(o.read())
        download(j["settings"]["web_host"]+"/download_data", j["settings"]["app_key"], sys.argv[1], j["settings"]["data_path"]+"/tmp.zip")
    
main()
