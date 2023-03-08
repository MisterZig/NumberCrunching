# Description: This is a test for collecting images from the NASA Mars Rover API
from requests import get

# Define the URL
URL:str = "https://api.nasa.gov/mars-photos/api/v1/rovers/perseverance/photos"
API_KEY:str = "DEMO_KEY"
SOL:int = 105


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

photos = getPhotos(URL, SOL, API_KEY, "MCZ_RIGHT")

print(photos)

save_photos = input("Do you want to save the photos? (y/n): ")

if save_photos == "y":
    savePhotosToTXT(photos, f"./MarsRoverImages/output/text_files/photos_on_sol_{SOL}.txt")