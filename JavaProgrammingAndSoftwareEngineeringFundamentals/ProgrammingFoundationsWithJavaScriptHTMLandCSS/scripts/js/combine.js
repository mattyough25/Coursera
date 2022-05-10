function combine(show,hide){
	var answer = new SimpleImage(show.getWidth(),show.getHeight());

	for(var px of answer.values()){
		var x = px.getX();
		var y = px.getY();

		var showPixel = show.getPixel(x,y);

		var hidePixel = hide.getPixel(x,y);

		px.setRed(showPixel.getRed() + hidePixel.getRed());
		px.setGreen(showPixel.getGreen() + hidePixel.getGreen());
		px.setBlue(showPixel.getBlue() + hidePixel.getBlue());
	}
	return answer;
}