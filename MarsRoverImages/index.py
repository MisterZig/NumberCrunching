
import sys
from requests import get

def getPhotos(url:str, sol:int, api_key:str, camera:str):
    """
    This function will get the photos from the NASA Mars Rover API
    """

    # Define the parameters
    PARAMS = {
        "sol":sol,
        "camera":camera,
        "api_key":api_key
    }

    # Get the response
    response = get(url, params=PARAMS)

    # Return the response
    return response.json()

def savePhotosToTXT(photos_response:dict, filename:str="photos.txt"):
    """
    This function will save the photos returned from the getPhotos to a text file where each line is a photo url and can be collected later using the wget command
    """
    photos = photos_response["photos"]

    # Open the file
    with open(filename, "w") as f:
        for photo in photos:
            f.write(photo["img_src"] + "\n")

if __name__ == "__main__":
    API_KEY = input("Enter API_KEY: ")
    URL = "https://api.nasa.gov/mars-photos/api/v1/rovers/perseverance/photos"

    if(sys.argv.length < 3):
        sol_end = 727
        if sys.argv.length < 2:
            sol_start = 1
    else:
        sol_start, sol_end = int(sys.argv[1]), int(sys.argv[2])

    for sol in range(130, 200):
        photos = getPhotos(URL, sol, API_KEY, "MCZ_RIGHT")

        print(photos)

        #save_photos = input("Do you want to save the photos? (y/n): ")

        #if save_photos == "y":
        savePhotosToTXT(photos, f"./MarsRoverImages/output/text_files/photos_on_sol_{sol}.txt")