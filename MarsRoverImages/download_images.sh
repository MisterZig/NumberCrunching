python3 download_images.py
cd ./output/images
for file in ../text_files/*.txt
do
    wget -i $file &
done