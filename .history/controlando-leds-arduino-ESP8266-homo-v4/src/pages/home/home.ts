import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { Http } from '@angular/http';
import 'rxjs/add/operator/map';
import 'rxjs/add/operator/timeout';
import 'rxjs/add/observable/range';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {

public led1 : boolean;
public led2 : boolean;
public led3 : boolean;
public led4 : boolean;



   constructor(public navCtrl: NavController,
               public params: NavParams,
               public http   : Http) {

   	this.led1 = false;
   	this.led2 = false;
   	this.led3 = false;
   	this.led4 = false;





  }
  
   public toggleled1(){
   	 if(this.led1){
   	  let urlDest = "http://192.168.0.16/?function=led1_on";
       this.http.get(urlDest).map(res => res.json()).subscribe(data => {
        console.log("LED 1 ATIVADO "+urlDest)
          });    
     }else{
   	  let urlDest = "http://192.168.0.16/?function=led1_off";
       this.http.get(urlDest).map(res => res.json()).subscribe(data => {
        console.log("LED 1 ATIVADO "+urlDest)
          });
     }   
   }

   public toggleled2(){
   	 if(this.led2){
   	  let urlDest = "http://192.168.0.16/?function=led2_on";
       this.http.get(urlDest).map(res => res.json()).subscribe(data => {
        console.log("LED 2 ATIVADO "+urlDest)
        });
     }else{
   	  let urlDest = "http://192.168.0.16/?function=led2_off";
       this.http.get(urlDest).map(res => res.json()).subscribe(data => {
        console.log("LED 2 DESATIVADO "+urlDest)
        });
     }   
   }
   public toggleled3(){
   	 if(this.led3){
   	  let urlDest = "http://192.168.0.16/?function=led3_on";
       this.http.get(urlDest).map(res => res.json()).subscribe(data => {
        console.log("LED 3 ATIVADO "+urlDest)
        });
     }else{
   	  let urlDest = "http://192.168.0.16/?function=led3_off";
       this.http.get(urlDest).map(res => res.json()).subscribe(data => {
        console.log("LED 3 DESATIVADO "+urlDest)
        });
     }   
   }
   public toggleled4(){
     if(this.led4){
      let urlDest = "http://192.168.0.16/?function=led4_on";
       this.http.get(urlDest).map(res => res.json()).subscribe(data => {
        console.log("LED 4 ATIVADO "+urlDest)
        });
     }else{
      let urlDest = "http://192.168.0.16/?function=led4_off";
       this.http.get(urlDest).map(res => res.json()).subscribe(data => {
        console.log("LED 4 DESATIVADO "+urlDest)
        });
     }   
   }
}
