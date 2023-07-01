/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JPanel.java to edit this template
 */
package test;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.Color;
import java.awt.geom.Line2D;
import java.awt.geom.Path2D;
import java.awt.geom.Point2D;
import java.awt.image.BufferedImage;

/**
 *
 * @author mario
 */
public class lienzo extends javax.swing.JPanel {
    private Shape s = null;
    private Color color = Color.black;
    private boolean relleno = false;
    private boolean trazado = false;
    private Shape trazo = null;
    BufferedImage img = null;

    /**
     * Creates new form lienzo
     */
    public lienzo() {
        initComponents();
    }
    
    @Override
    public void paint(Graphics g){
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        
        if (img != null) g2d.drawImage(img, 0, 0, this);
        
        else if (s != null){
            g2d.setPaint(color);
            
            if (relleno) g2d.fill(s);
            else g2d.draw(s);
        }
    }
    
    public void setShape (Shape s){
        this.s = s;
    }
    
    public void setColor (Color c){
        this.color = c;
    }
    
    public void setRelleno (boolean r){
        this.relleno = r;
    }
    
    public boolean getRelleno(){
        return relleno;
    }
    
    public void setTrazado (boolean t){
        this.trazado = t;
    }
    
    public void setImage (BufferedImage i){
        this.img = i;
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setBackground(new java.awt.Color(255, 255, 255));
        addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseDragged(java.awt.event.MouseEvent evt) {
                formMouseDragged(evt);
            }
        });
        addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                formMousePressed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents

    private void formMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMousePressed
        if (trazado){
            trazo = new Path2D.Float();
            ((Path2D) trazo).moveTo(evt.getX(), evt.getY());
        }
    }//GEN-LAST:event_formMousePressed

    private void formMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseDragged
        if (trazado && trazo != null){
            System.out.println("X: " + evt.getX() + " Y: " + evt.getY());
            ((Path2D) trazo).lineTo(evt.getX(), evt.getY());
            this.repaint();
        }
    }//GEN-LAST:event_formMouseDragged


    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
