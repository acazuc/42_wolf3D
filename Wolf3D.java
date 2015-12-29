package com.jukino.ft.wolf3d;

import org.lwjgl.LWJGLException;
import org.lwjgl.input.Keyboard;
import org.lwjgl.input.Mouse;
import org.lwjgl.opengl.Display;

import com.jukino.utils.Color;
import com.jukino.utils.Draw;

public class Wolf3D {
	
	private static final int SPEED_FACTOR = 3;
	
	private static int[][] map;
	private static double playerX;
	private static double playerY;
	private static double dirX;
	private static double dirY;
	private static double planeX;
	private static double planeY;
	
	public static void main(String[] args) {
		try {
			System.setProperty("org.lwjgl.librarypath", new java.io.File("lib/lwjgl/windows").getAbsolutePath());
			Window.init(1280, 720, "Wolf3D");
			Window.enableVSync();
			initMap();
			Mouse.setGrabbed(true);
			playerX = map[0].length/2;
			playerY = map.length/2;
			dirX = -1;
			dirY = 0;
			planeX = 0;
			planeY = 0.9;
			while(!Display.isCloseRequested()) {
				Window.clearRender();
				event();
				draw();
				Window.updateDisplay();
			}
		}
		catch(LWJGLException e) {
			e.printStackTrace();
		}
	}
	
	private static void event() {
		double dx = Mouse.getDX()/-360.;
		double oldDirX = dirX;
	    dirX = dirX*Math.cos(dx)-dirY*Math.sin(dx);
	    dirY = oldDirX*Math.sin(dx)+dirY*Math.cos(dx);
	    double oldPlaneX = planeX;
	    planeX = planeX*Math.cos(dx)-planeY*Math.sin(dx);
	    planeY = oldPlaneX*Math.sin(dx)+planeY*Math.cos(dx);
		double oldPlayerX = playerX;
		double oldPlayerY = playerY;
        if(Keyboard.isKeyDown(Keyboard.KEY_Z)) {
        	playerX+= dirX/60*SPEED_FACTOR;
        	playerY+= dirY/60*SPEED_FACTOR;
        }
        if(Keyboard.isKeyDown(Keyboard.KEY_S)) {
        	playerX-= dirX/60*SPEED_FACTOR;
        	playerY-= dirY/60*SPEED_FACTOR;
        }
        if(Keyboard.isKeyDown(Keyboard.KEY_ESCAPE)) {
        	System.exit(0);
        }
        if(playerX < 0 || playerX >= map[0].length) {
        	playerX = oldPlayerX;
        }
        if(playerY < 0 || playerY >= map.length) {
        	playerY = oldPlayerY;
        }
        if(map[(int)oldPlayerY][(int)playerX] == 1) {
        	playerX = oldPlayerX;
        }
        if(map[(int)playerY][(int)oldPlayerX] == 1) {
        	playerY = oldPlayerY;
        }
	}
	
	private static void draw() {
		Draw.drawColorQuad(0, 0, Window.getWidth(), Window.getHeight()/2, Color.BLACK);
		Draw.drawColorQuad(0, Window.getHeight()/2, Window.getWidth(), Window.getHeight()/2, Color.GREY);
		int x = 0;
		while(x < Window.getWidth()) {
			drawLine(x);
			x++;
		}
	}
	
	private static void drawLine(int x) {
	    double cameraX = 2*x/(double)Window.getWidth()-1;
	    double rayPosX = playerX;
	    double rayPosY = playerY;
	    double rayDirX = dirX+planeX*cameraX;
	    double rayDirY = dirY+planeY*cameraX;
	    int mapX = (int)rayPosX;
	    int mapY = (int)rayPosY;
	    double sideDistX;
	    double sideDistY;
	    double deltaDistX = Math.sqrt(1+(rayDirY*rayDirY)/(rayDirX*rayDirX));
	    double deltaDistY = Math.sqrt(1+(rayDirX*rayDirX)/(rayDirY*rayDirY));
	    double perpWallDist;
	    int stepX;
	    int stepY;
	    int hit = 0;
	    int side = 0;
	    if(rayDirX < 0) {
	    	stepX = -1;
	    	sideDistX = (rayPosX-mapX)*deltaDistX;
	    }
	    else {
	    	stepX = 1;
	    	sideDistX = (mapX+1.0-rayPosX)*deltaDistX;
	    }
	    if(rayDirY < 0) {
	    	stepY = -1;
	    	sideDistY = (rayPosY-mapY)*deltaDistY;
	    }
	    else {
	    	stepY = 1;
	    	sideDistY = (mapY+1.0-rayPosY)*deltaDistY;
	    }
	    while(hit == 0) {
	    	if(sideDistX < sideDistY) {
	    		sideDistX+= deltaDistX;
	    		mapX+= stepX;
	    		if(stepX < 0) {
	    			side = 0;
	    		}
	    		else {
	    			side = 1;
	    		}
	    	}
	        else {
	        	sideDistY+= deltaDistY;
	        	mapY+= stepY;
	        	if(stepY < 0) {
	        		side = 2;
	        	}
	        	else {
	        		side = 3;
	        	}
	        }
	        if(mapX < 0 || mapX >= map[0].length || mapY < 0 || mapY >= map.length || map[mapY][mapX] > 0) {
	        	hit = 1;
	        }
	    } 
	    if(side == 0 || side == 1) {
	    	  perpWallDist = Math.abs((mapX-rayPosX+(1-stepX)/2)/rayDirX);
	    }
	    else {
	    	perpWallDist = Math.abs((mapY-rayPosY+(1-stepY)/2)/rayDirY);
	    }
	    double lineHeight = Math.abs((int)(Window.getHeight()/perpWallDist));
	    double drawStart = -lineHeight/2.+Window.getHeight()/2.;
	    if(drawStart < 0) {
	    	drawStart = 0;
	    }
	    double drawEnd = lineHeight/2+Window.getHeight()/2.;
	    if(drawEnd >= Window.getHeight()) {
	    	drawEnd = Window.getHeight() - 1;
	    }
	    Color color = Color.RED;
	    if(side == 1) {
	    	color = Color.BLUE; 
	    }
	    else if(side == 2) {
	    	color = Color.GREEN;
	    }
	    else if(side == 3) {
	    	color = Color.YELLOW;
	    }
	    Draw.drawLine(x, (int)drawStart, x, (int)drawEnd, color);
	}
	
	private static void initMap() {
		map = new int[][]{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
						, {1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1}
						, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
						, {1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1}
						, {1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1}
						, {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1}
						, {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}
						, {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1}
						, {1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1}
						, {1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1}
						, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
						, {1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1}
						, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
	}
	
}
