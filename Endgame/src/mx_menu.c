#include "../inc/virus.h"


#define WIDTH 1200
#define HEIGHT 750
#define WI (WIDTH/3.36)
#define HE (HEIGHT/13.6)

int mx_menu(SDL_Renderer *render){
    bool quit = 1;
    bool men = 1;
    bool rules = 0;
    bool game = 0;
    int x, y;

    //SCREEN CONSTANTS

    //VAR FOR EVENTS
    SDL_Event event;

    //VARS FOR WINDOW, RENDERER
   
    //VARS FOR MENU IMAGES
    SDL_Texture *background_tex = NULL;
    SDL_Surface *background_surf = NULL;
    SDL_Texture *starty_tex = NULL;
    SDL_Surface *starty_surf = NULL;
    SDL_Texture *rulesg_tex = NULL;
    SDL_Surface *rulesg_surf = NULL;
    SDL_Texture *exitg_tex = NULL;
    SDL_Surface *exitg_surf = NULL;
    SDL_Texture *startg_tex = NULL;
    SDL_Surface *startg_surf = NULL;
    SDL_Texture *rulesy_tex = NULL;
    SDL_Surface *rulesy_surf = NULL;
    SDL_Texture *exity_tex = NULL;
    SDL_Surface *exity_surf = NULL;

    //VARS FOR RULES IMAGES
    SDL_Surface *blackbackg_surf = NULL;
    SDL_Texture *blackbackg_tex = NULL;

    SDL_Surface *keyboard_surf = NULL;
    SDL_Texture *keyboard_tex = NULL;

    SDL_Surface *okg_surf = NULL;
    SDL_Texture *okg_tex = NULL;
    SDL_Surface *oky_surf = NULL;
    SDL_Texture *oky_tex = NULL;

    SDL_Surface *p1_surf = NULL;
    SDL_Texture *p1_tex = NULL;
    SDL_Surface *pp1_surf = NULL;
    SDL_Texture *pp1_tex = NULL;
    SDL_Surface *p2_surf = NULL;
    SDL_Texture *p2_tex = NULL;
    SDL_Surface *p3_surf = NULL;
    SDL_Texture *p3_tex = NULL;
    SDL_Surface *pp3_surf = NULL;
    SDL_Texture *pp3_tex = NULL;
    SDL_Surface *ppp3_surf = NULL;
    SDL_Texture *ppp3_tex = NULL;
    SDL_Surface *p4_surf = NULL;
    SDL_Texture *p4_tex = NULL;
    SDL_Surface *pp4_surf = NULL;
    SDL_Texture *pp4_tex = NULL;
    SDL_Surface *p5_surf = NULL;
    SDL_Texture *p5_tex = NULL;

    //VARS FOR RULES TEXT
    SDL_Surface *rules_t_surf = NULL;
    SDL_Texture *rules_t_text = NULL;
    
    const char* RULES = "RULES";
    const char* p1 = "1. AVOId MEETINGS WITH CORONA-VIRUS";
    const char* p2 = "2. MOVEMENT";
    const char* p3 = "3. PICK UP COINS TO GET ANTISEPTIC";
    const char* p4 = "4. HAVING RECEIVEd IT THE VIRUS dIES";
    const char* pp4 = "ANd YOU FIINISH THE GAME";
    const char* p5 = "5. YOU LOOSE WHEN YOU MEET THE VIRUS";

    
    //VARS FOR RULES FONT AND SIZE OF TEXT
    TTF_Font *font_rules = NULL;
    int size_font = HE/2; 

    //VARS FOR RULES COLOR TEXT
    SDL_Color color_r = {255, 0, 0, 0};
    SDL_Color color_g = {30, 255, 80, 0};
    
    /*POSITION OF MENU BUTTONS*/
    SDL_Rect start_pos;
    CreateRectangle(&start_pos, (WIDTH/2) - (WI/2) - 0.03*WIDTH, (HEIGHT/2) - HE, WI*1.3, HE);

    SDL_Rect rules_pos;
    CreateRectangle(&rules_pos, (WIDTH/2) - (WI/2) + 0.3*WI, (HEIGHT/2) + HE - 0.3*HE, WI/2, HE/2 + 0.4*HE);
    
    SDL_Rect exit_pos;
    CreateRectangle(&exit_pos, (WIDTH/2) - (WI/2) + 0.45*WI, (HEIGHT/2) + 2*HE + 0.3*HE, WI/4, HE/2);

    /*POSITION OF TEXT, IMAGES AND BUTTON "OK" IN RULES*/

    /*TEXT*/
    
    SDL_Rect rules_text;
    CreateRectangle(&rules_text, (WIDTH/2) - (WI/2), HEIGHT/14 - (HE/2), WI, HE);
    
    /*IMAGES*/
    SDL_Rect p1_pos;
    CreateRectangle(&p1_pos, (WIDTH/4) - (WI/2), HEIGHT/6.15 - (HE/2), 2*WI, HE*0.8);

    SDL_Rect pp1_pos;
    CreateRectangle(&pp1_pos, (WIDTH/1.15) - (WI/2), HEIGHT/6.25 - (HE/2), WI/2.5, HE);

    SDL_Rect p2_pos;
    CreateRectangle(&p2_pos, (WIDTH/4) - (WI/2), HEIGHT/4 - (HE/2), 0.85*WI, HE*0.65);
    
    SDL_Rect p3_pos;
    CreateRectangle(&p3_pos, (WIDTH/4) - (WI/2), HEIGHT/1.95 - (HE/2), 2*WI, HE*0.8);

    SDL_Rect pp3_pos;
    CreateRectangle(&pp3_pos, (WIDTH/1.05) - (WI/2), HEIGHT/2.1 - (HE/2), WI/2.6, HE*1.3);

    SDL_Rect ppp3_pos;
    CreateRectangle(&ppp3_pos, (WIDTH/1.15) - (WI/2), HEIGHT/1.9 - (HE/2), WI/3.25, HE*0.45);

    SDL_Rect p4_pos;
    CreateRectangle(&p4_pos, (WIDTH/4) - (WI/2), HEIGHT/1.65 - (HE/2), 2.55*WI, HE*0.8);

    SDL_Rect pp4_pos;
    CreateRectangle(&pp4_pos, (WIDTH/3.62) - (WI/2), HEIGHT/1.5 - (HE/2), 1.5*WI, HE*0.65);

    SDL_Rect p5_pos;
    CreateRectangle(&p5_pos, (WIDTH/4) - (WI/2), HEIGHT*0.75 - (HE/2), 2.55*WI, HE*0.8);

    SDL_Rect keyboard_pos;
    CreateRectangle(&keyboard_pos, (WIDTH/3.2) - (WI/2), (HEIGHT/3.25) - (HE/2), WIDTH*0.2, HEIGHT*0.2);
    
    /*BUTTON*/
    SDL_Rect ok_r_pos;
    CreateRectangle(&ok_r_pos, (WIDTH/2.2) - (WI/6), (HEIGHT*0.9) - (HE/2), 0.5*WI, HE*1.2);    

    // DIRS OF IMAGES
    //MENU
    const char* dir_background = "resource/background.bmp";
    const char* dir_start_g = "resource/startgame_g.bmp";
    const char* dir_rules_g = "resource/rules_g.bmp";
    const char* dir_exit_g = "resource/exit_g.bmp";
    const char* dir_start_y = "resource/startgame_y.bmp";
    const char* dir_rules_y = "resource/rules_y.bmp";
    const char* dir_exit_y = "resource/exit_y.bmp";

    //RULES
    const char* dir_blackback = "resource/black_background.bmp";
    const char* dir_keyboard = "resource/keyboard.png";
    const char* dir_ok_g = "resource/ok_g.bmp";
    const char* dir_ok_y = "resource/ok_y.bmp";
    //const char* dir_p1 = "resource/p1.png";
    const char* dir_pp1 = "resource/virus_rules.bmp";
    //const char* dir_p2 = "resource/.bmp";
    //const char* dir_p3 = "resource/.bmp";
    const char* dir_pp3 = "resource/ANTISEPTIC.png";
    const char* dir_ppp3 = "resource/COIN.png";
    
    

    //DIR OF FONT
    const char* fontDir = "resource/COOPBL.ttf";
   
    

    //MENU TEXTURES
    CreateTextureImage(dir_background, &background_surf, render, &background_tex);
    CreateTextureImage(dir_start_g, &startg_surf, render, &startg_tex);
    CreateTextureImage(dir_start_y, &starty_surf, render, &starty_tex);
    CreateTextureImage(dir_rules_g, &rulesg_surf, render, &rulesg_tex);
    CreateTextureImage(dir_rules_y, &rulesy_surf, render, &rulesy_tex);
    CreateTextureImage(dir_exit_g, &exitg_surf, render, &exitg_tex);
    CreateTextureImage(dir_exit_y, &exity_surf, render, &exity_tex);

    //RULES TEXTURES IMAGE
    CreateTextureImage(dir_blackback, &blackbackg_surf, render, &blackbackg_tex);
    CreateTextureImage(dir_keyboard, &keyboard_surf, render, &keyboard_tex);
    CreateTextureImage(dir_ok_g, &okg_surf, render, &okg_tex);
    CreateTextureImage(dir_ok_y, &oky_surf, render, &oky_tex);
    //CreateTextureImage(dir_p1, &p1_surf, render, &p1_tex);
    CreateTextureImage(dir_pp1, &pp1_surf, render, &pp1_tex);
    CreateTextureImage(dir_pp3, &pp3_surf, render, &pp3_tex);
    CreateTextureImage(dir_ppp3, &ppp3_surf, render, &ppp3_tex);


    //RULES TEXTURES TEXT
    CreateTextureText(&font_rules, fontDir, size_font, &rules_t_surf,  RULES, color_r, &rules_t_text, render);
    CreateTextureText(&font_rules, fontDir, size_font/2, &p1_surf,  p1, color_g, &p1_tex, render);
    CreateTextureText(&font_rules, fontDir, size_font/2, &p2_surf,  p2, color_g, &p2_tex, render);
    CreateTextureText(&font_rules, fontDir, size_font/2, &p3_surf,  p3, color_g, &p3_tex, render);
    CreateTextureText(&font_rules, fontDir, size_font/2, &p4_surf,  p4, color_g, &p4_tex, render);
    CreateTextureText(&font_rules, fontDir, size_font/2, &pp4_surf,  pp4, color_g, &pp4_tex, render);
    CreateTextureText(&font_rules, fontDir, size_font/2, &p5_surf,  p5, color_g, &p5_tex, render);
    

    //CLEAN/PREPARE THE SCREEN FROM RUBBISH
    SDL_RenderClear(render);

    //KEEP IN MIND THE BACKGROUND, GREEN BUTTONS: "START GAME", "RULES", "EXIT"
    SDL_RenderCopy(render, background_tex, NULL, NULL);
    SDL_RenderCopy(render, startg_tex, NULL, &start_pos);
    SDL_RenderCopy(render, rulesg_tex, NULL, &rules_pos);
    SDL_RenderCopy(render, exitg_tex, NULL, &exit_pos);

    //SHOW ON THE SCREEN EVERYTHING FROM THE CURRENT "MIND"
    SDL_RenderPresent(render);

    while (quit)  //START PLAYING!
    {
        while(SDL_PollEvent(&event)){  /*START EVENTS*/
            if (men){ /*menu part events*/
                switch (event.type)     
                {
                    case SDL_QUIT:      /*quit by X in the right upper corner*/
                        quit = 0;
                        break;
                    case SDL_MOUSEMOTION:   /*MOUSE MOTION*/
                        x = event.motion.x; // STORE THE POSITION OF 
                        y = event.motion.y; // CURSOR

                        //CURSOR IS AT "START GAME"?
                        if (x > start_pos.x && x < start_pos.x + start_pos.w && y > start_pos.y && y < start_pos.y + start_pos.h){
                            // KEEP IN MIND YELLOW "STARTGAME"
                            SDL_RenderCopy(render, starty_tex, NULL, &start_pos);   
                        }
                        //CURSOR IS AT "RULES"?
                        else if (x > rules_pos.x && x < rules_pos.x + rules_pos.w && y > rules_pos.y && y < rules_pos.y + rules_pos.h){
                            // KEEP IN MIND YELLOW "RULES"
                            SDL_RenderCopy(render, rulesy_tex, NULL, &rules_pos);
                        }
                        //CURSOR IS AT "EXIT"?
                        else if (x > exit_pos.x && x < exit_pos.x + exit_pos.w && y > exit_pos.y && y < exit_pos.y + exit_pos.h){
                            // KEEP IN MIND YELLOW "EXIT"
                            SDL_RenderCopy(render, exity_tex, NULL, &exit_pos);
                        }
                        //CURSOR ISN'T AT BUTTONS ABOVE?
                        else {
                            //KEEP IN MIND ALL GREEN BUTTONS
                            SDL_RenderCopy(render, startg_tex, NULL, &start_pos);
                            SDL_RenderCopy(render, rulesg_tex, NULL, &rules_pos);
                            SDL_RenderCopy(render, exitg_tex, NULL, &exit_pos);
                        }
                        //SHOW ON THE SCREEN EVERYTHING FROM THE CURRENT "MIND"
                        SDL_RenderPresent(render);
                        break;
                    case SDL_MOUSEBUTTONDOWN: /*YOU CLICKED 1 time*/
                        x = event.button.x;   //STORE THE POSITION OF
                        y = event.button.y;   //CLICKING
                        //YOU CLICKED ON RULES?
                        if (x > rules_pos.x && x < rules_pos.x + rules_pos.w && y > rules_pos.y && y < rules_pos.y + rules_pos.h){
                            //KEEP IN MIND THE BACKGROUND, TEXT, BUTTONS OF RULES PART
                            SDL_RenderCopy(render, blackbackg_tex, NULL, NULL);
                            SDL_RenderCopy(render, rules_t_text, NULL, &rules_text);
                            SDL_RenderCopy(render, keyboard_tex, NULL, &keyboard_pos);
                            SDL_RenderCopy(render, okg_tex, NULL, &ok_r_pos);
                            SDL_RenderCopy(render, p1_tex, NULL, &p1_pos);
                            SDL_RenderCopy(render, pp1_tex, NULL, &pp1_pos);
                            SDL_RenderCopy(render, p2_tex, NULL, &p2_pos);
                            SDL_RenderCopy(render, p3_tex, NULL, &p3_pos);
                            SDL_RenderCopy(render, pp3_tex, NULL, &pp3_pos);
                            SDL_RenderCopy(render, ppp3_tex, NULL, &ppp3_pos);
                            SDL_RenderCopy(render, p4_tex, NULL, &p4_pos);
                            SDL_RenderCopy(render, pp4_tex, NULL, &pp4_pos);
                            SDL_RenderCopy(render, p5_tex, NULL, &p5_pos);
                            //TURN ON RULES PART EVENT
                            //TURN ON RULES PART EVENT
                            rules = 1;
                            //TURN OFF MENU PART EVENT
                            men = 0;
                        }
                        //YOU CLICKED ON EXIT?
                        else if (x > exit_pos.x && x < exit_pos.x + exit_pos.w && y > exit_pos.y && y < exit_pos.y + exit_pos.h){
                            //TURN OFF MENU PART EVENT
                            men = 0;
                            //OH, DEAR, FAREWELL!
                            quit = 0;
                        }
                        //YOU CLICKED ON START GAME??
                        else if(x > start_pos.x && x < start_pos.x + start_pos.w && y > start_pos.y && y < start_pos.y + start_pos.h){
                            //TURN OFF MENU PART EVENT
                            men = 0;
                            //GO PLAY
                            game = 1;
                            quit = 0;
                        }

                        //SHOW ON THE SCREEN EVERYTHING FROM THE CURRENT "MIND"
                        SDL_RenderPresent(render);
                        break;
                }
            }
            else if (rules){ /*rules events*/
                switch (event.type){
                    case SDL_QUIT:      /*quit by X in the right upper corner*/
                        quit = 0;
                        break;
                    case SDL_MOUSEMOTION:   /*MOUSE MOTION*/
                        x = event.motion.x; // STORE THE POSITION OF 
                        y = event.motion.y; // CURSOR

                        //CURSOR IS AT "OK"?
                        if (x > ok_r_pos.x && x < ok_r_pos.x + ok_r_pos.w && y > ok_r_pos.y && y < ok_r_pos.y + ok_r_pos.h){
                            // KEEP IN MIND YELLOW "OK"
                            SDL_RenderCopy(render, oky_tex, NULL, &ok_r_pos);   
                        }
                        else {
                            SDL_RenderCopy(render, okg_tex, NULL, &ok_r_pos);
                        }
                        break;
                    case SDL_MOUSEBUTTONDOWN: /*YOU CLICKED 1 time*/
                        x = event.button.x;   //STORE THE POSITION OF
                        y = event.button.y;   //CLICKING
                        //YOU CLICKED ON "OK"?
                        if (x > ok_r_pos.x && x < ok_r_pos.x + ok_r_pos.w && y > ok_r_pos.y && y < ok_r_pos.y + ok_r_pos.h){
                            //KEEP IN MIND THE BACKGROUND, TEXT, BUTTONS OF MENU PART
                            SDL_RenderCopy(render, background_tex, NULL, NULL);
                            SDL_RenderCopy(render, startg_tex, NULL, &start_pos);
                            SDL_RenderCopy(render, rulesg_tex, NULL, &rules_pos);
                            SDL_RenderCopy(render, exitg_tex, NULL, &exit_pos);
                            //TURN OFF RULES PART EVENT
                            rules = 0;
                            //TURN ON MENU PART EVENT
                            men = 1;
                        }
                        break;
                }
                SDL_RenderPresent(render);
            }
            else{
                if (event.type == SDL_QUIT) /*quit by X in the right upper corner*/
                    quit = 0;
            }
        }
    }



    SDL_DestroyTexture(p5_tex);
    SDL_DestroyTexture(pp4_tex);
    SDL_DestroyTexture(p4_tex);
    SDL_DestroyTexture(pp3_tex);
    SDL_DestroyTexture(ppp3_tex);
    SDL_DestroyTexture(pp1_tex);
    SDL_DestroyTexture(p3_tex);
    SDL_DestroyTexture(p2_tex);
    SDL_DestroyTexture(p1_tex);
    SDL_DestroyTexture(keyboard_tex);
    SDL_DestroyTexture(rules_t_text);
    SDL_DestroyTexture(oky_tex);
    SDL_DestroyTexture(okg_tex); 
    SDL_DestroyTexture(blackbackg_tex);   
    SDL_DestroyTexture(background_tex);
    SDL_DestroyTexture(starty_tex);
    SDL_DestroyTexture(rulesg_tex);
    SDL_DestroyTexture(exitg_tex);
    SDL_DestroyTexture(startg_tex);
    SDL_DestroyTexture(rulesy_tex);
    SDL_DestroyTexture(exity_tex);
    if (game)
        return 1;
    else return 0;
}
