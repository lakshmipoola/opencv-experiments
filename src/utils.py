import cv2

def show_video(video_file):
    """Open video and show it in window."""
    video = cv2.VideoCapture(video_file)
    print("Video is open.")

    ret, frame = video.read()
    while frame is not None:
        cv2.imshow('frame', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        ret, frame = video.read()

def main():
     show_video("data/test.avi")

if __name__ == "__main__":
    main()
